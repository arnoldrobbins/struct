/* 0.alloc.c: */
struct coreblk;
extern void freegraf(void);
extern void *challoc(int n);
extern void chfree(void *p, int n);
extern void *balloc(int n, struct coreblk **p, int size);
extern void *talloc(int n);
extern void *galloc(int n);
extern void reuse(struct coreblk *p);
extern void bfree(struct coreblk *p);
extern struct coreblk *morespace(int n, struct coreblk **p, int size);
extern void error(char *mess1, char *mess2, char *mess3);
extern void faterr(char *mess1, char *mess2, char *mess3);
extern void strerr(char *mess1, char *mess2, char *mess3);
extern void *challoc(int n);

/* 0.args.c: */
extern void getargs(int argc, char *argv[]);
extern void setsw(char *str);

/* 0.graph.c: */
extern void prgraph(void);
extern void prtree(void);
extern void prtr(VERT v,int tab);
extern void tabover(int n, FILE *fd);

/* 0.list.c: */
extern struct list *consls(VERT v, struct list *ls);
extern struct list *append(VERT v, struct list *ls);
extern void freelst(struct list *ls);
extern VERT oneelt(struct list *ls);
extern int lslen(struct list *ls);
extern void prlst(struct list *ls);

/* 0.parts.c: */
extern VERT *arc(VERT v, int i);
extern VERT *lchild(VERT v, int i);
extern int *vxpart(VERT v, int type, int j);
extern int *expres(VERT v);
extern int *negpart(VERT v);
extern int *predic(VERT v);
extern int *level(VERT v);
extern int *stlfmt(VERT v, int n);
extern int create(int type, int arcnum);

/* 0.string.c: */
extern int str_copy(char *s, char *ptr, int length);
extern int find(char *s, char *ar[], int size);
extern int str_eq(char s[], char t[]);
extern int classmatch(char c, int i);
extern void copychars(char *cbeg, char *target, int n);
extern void copycs(char *cbeg, char *target, int n);
extern int slength(char *s);
extern char *concat(char *x, char *y);

/* 1.init.c: */
extern void prog_init(void);
extern void routinit(void);
extern void line_init(void);
extern void graf_init(void);

/* 1.finish.c: */
extern void fingraph(void);
extern VERT addum(VERT v, struct list *lst);

/* 1.form.c */
extern int uptolow(int c);
extern void rdfree( int (*func)() );
extern void rdstand( int (*func)() );
extern void labfree( int (*func)() );
extern void labstand( int (*func)() );
extern int contfree(void);
extern int nonblchar(int class, int yesno);
extern int contstand(void);
extern int comstand(int posafter);
extern int comfree(int posafter);
extern int blankline(void);
extern void empseek(unsigned int linebeg);
extern int inchar(void);
extern void unchar(int c);

/* 1.fort.c: */
extern VERT act(int k, int c, int bufptr);
extern struct lablist *makelab(long x);
extern long label(int i);
extern void freelabs(void);
extern char *stralloc(char *ad, int n);
extern char *remtilda(char *s);

/* 1.hash.c: */
extern int parse(void);
extern void hash_init(void);
extern void hash_check(void);
extern void hash_free(void);
extern int hash(long x);
extern void addref(long x, int *ptr);
extern void connect(long x, long y);
extern void clear(long x);

/* 1.line.c: */
int
get_a_line(int *lastline, long *lastchar, int *linecom, long *charcom);


/* 1.main.c: */
extern int mkgraph(void);

/* 1.node.c: */
extern VERT makenode(int type, LOGICAL addimp, LOGICAL addcom, long labe, int arcnum, int arctype[], long arclab[]);
extern void fiximp(VERT num, long labe);

/* 1.recog.c: */
extern void recognize(int type, int ifflag);

/* 2.main.c: */
extern void build(void);

/* 3.main.c: */
extern void structure(void);

/* 4.main.c: */
extern void output(void);
