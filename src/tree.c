#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "y.tab.h"
#include "b.h"

struct node *
addroot(char *string, int type, struct node *n1, struct node *n2)
{
	struct node *p;

	p = malloc(sizeof(*p));
	p->left = n1;
	p->right = n2;
	p->op = type;
	p->lit = malloc(strlen(string) + 1);
	strcpy(p->lit, string);
	return p;
}


void
freetree(struct node *tree)
{
	if (tree) {
		freetree(tree->left);
		freetree(tree->right);
		freenode(tree);
	}
}

void
freenode(struct node *treenode)
{
	free(treenode->lit);
	free(treenode);
}

int compop[] = { '&', '|', '<', '>', xxeq, xxle, xxne, xxge };
int notop[] = { '|', '&', xxge, xxle, xxne, '>', xxeq, '<' };
char *opstring[] = { "||", "&&", ">=", "<=", "!=", ">", "==", "<" };

struct node *
checkneg(struct node *tree, int neg)	/* eliminate nots if possible */
{
	int i;
	struct node *t;

	if (!tree)
		return 0;
	for (i = 0; i < 8; ++i)
		if (tree->op == compop[i])
			break;
	if (i > 1 && i < 8 && tree->left->op == '-'
	    && strcmp(tree->right->lit, "0") == 0) {
		t = tree->right;
		tree->right = tree->left->right;
		freenode(t);
		t = tree->left;
		tree->left = tree->left->left;
		freenode(t);
	}


	if (neg) {
		if (tree->op == '!') {
			t = tree->left;
			freenode(tree);
			return checkneg(t, 0);
		}
		if (i < 8) {
			tree->op = notop[i];
			free(tree->lit);
			tree->lit = malloc(strlen(opstring[i]) + 1);
			strcpy(tree->lit, opstring[i]);
			if (tree->op == '&' || tree->op == '|') {
				tree->left = checkneg(tree->left, 1);
				tree->right = checkneg(tree->right, 1);
			}
			return tree;
		}
		if (tree->op == xxident && strcmp(tree->lit, ".false.") == 0)
			strcpy(tree->lit, ".true.");
		else if (tree->op == xxident
			 && strcmp(tree->lit, ".true.") == 0) {
			free(tree->lit);
			tree->lit = malloc(strlen(".false.") + 1);
			strcpy(tree->lit, ".false.");
		} else {
			tree = addroot("!", '!', tree, 0);
			tree->lit = malloc(2);
			strcpy(tree->lit, "!");
		}
		return tree;
	} else if (tree->op == '!') {
		t = tree;
		tree = tree->left;
		freenode(t);
		return checkneg(tree, 1);
	} else {
		tree->left = checkneg(tree->left, 0);
		tree->right = checkneg(tree->right, 0);
		return tree;
	}
}

void
yield(struct node *tree,
      int fprec)		/* fprec is precedence of father of this node */
{
	int paren, p;
	static int oplast;	/* oplast = 1 iff last char printed was operator */

	if (!tree)
		return;
	p = prec(tree->op);
	paren = (p < fprec || (oplast && tree->op == xxuminus)) ? 1 : 0;

	if (paren) {
		putout('(', "(");
		oplast = 0;
	}

	switch (tree->op) {
	case xxuminus:
		tree->op = '-';
	case '!':
		putout(tree->op, tree->lit);
		oplast = 1;
		yield(tree->left, p);
		break;
	case '&':
	case '|':
	case '<':
	case '>':
	case xxeq:
	case xxne:
	case xxle:
	case xxge:
	case '+':
	case '-':
	case '*':
	case '/':
	case '^':
		yield(tree->left, p);
		putout(' ', " ");
		putout(tree->op, tree->lit);
		putout(' ', " ");
		oplast = 1;
		yield(tree->right, p);
		break;
	case xxidpar:
		yield(tree->left, 0);
		putout('(', "(");
		oplast = 0;
		yield(tree->right, 0);
		putout('(', ")");
		oplast = 0;
		break;
	default:
		yield(tree->left, p);
		putout(tree->op, tree->lit);
		oplast = 0;
		yield(tree->right, p);
		break;
	}
	if (paren) {
		putout(')', ")");
		oplast = 0;
	}
}

void
puttree(struct node *tree)
{
	yield(tree, 0);
	freetree(tree);
}


int
prec(int oper)
{
	switch (oper) {
	case ',':
		return 0;
	case '|':
		return 1;
	case '&':
		return 2;
	case '!':
		return 3;

	case '<':
	case '>':
	case xxeq:
	case xxne:
	case xxle:
	case xxge:
		return 4;
	case '+':
	case '-':
		return 5;
	case '*':
	case '/':
		return 6;
	case xxuminus:
		return 7;
	case '^':
		return 8;
	default:
		return 9;
	}
}
