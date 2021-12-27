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


/* 1.main.c: */
extern int mkgraph(void);

/* 2.main.c: */
extern void build(void);

/* 3.main.c: */
extern void structure(void);

/* 4.main.c: */
extern void output(void);
