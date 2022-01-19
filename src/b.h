extern int xxindent, xxval, newflag, xxmaxchars, xxbpertab;
extern int xxlineno;		/* # of lines already output */
#define xxtop	100		/* max size of xxstack */
extern int xxstind, xxstack[xxtop], xxlablast;
struct node {
	int op;
	char *lit;
	struct node *left;
	struct node *right;
};
extern struct node *xxt;

/* tree.c: */
extern struct node *addroot(char *string, int type, struct node *n1, struct node *n2);
extern void freetree(struct node *tree);
extern void freenode(struct node *treenode);
extern struct node *checkneg(struct node *tree, int neg);
extern void yield(struct node *tree, int fprec);
extern void puttree(struct node *tree);
extern int prec(int oper);
extern int str_copy(char *s, char *cptr, int length);

/* beauty.y: */
extern void putout(int type, char *string);
extern void tab(int n);
extern void newline(void);
extern void error(char *mess1, char *mess2, char *mess3);
extern void push(int type);
extern void pop(void);
extern void forst(void);

/* lextab.l: */
extern int rdchar(void);
extern void backup(int c);
extern void nunput(int c);
extern int ninput(void);
extern int addbuf(int c);
extern void fixval(void);
extern void putback(char *str);
