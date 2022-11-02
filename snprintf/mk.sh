OUTDIR=../out
mkdir -p $OUTDIR

gcc -o $OUTDIR/long_int long_int.cpp
gcc -o $OUTDIR/sprintf sprintf.cpp
gcc -o $OUTDIR/snprintf snprintf.cpp
