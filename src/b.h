extern int xxindent, xxval, newflag, xxmaxchars, xxbpertab;
extern int xxlineno;		/* # of lines already output */
#define xxtop	100		/* max size of xxstack */
extern int xxstind, xxstack[xxtop], xxlablast, xxt;
struct node {
	int op;
	char *lit;
	struct node *left;
	struct node *right;
};

/* tree.c: */
extern struct node *addroot(char *string, int type, struct node *n1, struct node *n2);
extern void freetree(struct node *tree);
extern void freenode(struct node *treenode);
extern struct node *checkneg(struct node *tree, int neg);
extern void yield(struct node *tree, int fprec);
extern void puttree(struct node *tree);
extern int prec(int oper);
extern int str_copy(char *s, char *cptr, int length);
extern int str_eq(char s[], char t[]);
extern int slength(char *s);

/* beauty.y: */
extern void putout(int type, char *string);

