rm *.o *.a *.so 2> /dev/null

OUTDIR=../out

mkdir -p $OUTDIR

gcc -c test.c

ar cr libtest.a test.o

gcc -o $OUTDIR/app app.c -L. -ltest
