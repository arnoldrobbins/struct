#define YESTAB	true
#define NOTAB	false
#define TABOVER(n)	tabover(n, outfd)
#define OUTSTR(x)	fprintf(outfd, "%s", x)
#define OUTNUM(x)	fprintf(outfd, "%" PRIdPTR, x)


extern bool *brace;
#define YESBRACE(v,i)	{ if (DEFINED(LCHILD(v,i))) brace[LCHILD(v,i)] = true; }
#define NOBRACE(v,i)	{ if (DEFINED(LCHILD(v,i))) brace[LCHILD(v,i)] = false; }
#define HASBRACE(v,i)	 ((DEFINED(LCHILD(v,i))) ? brace[LCHILD(v,i)] : true)
