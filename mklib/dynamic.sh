# 동적 링크되는 라이브러리 만드는 법
#
rm *.o *.a *.so 2> /dev/null

gcc -c -fPIC test.c
gcc -c app.c

gcc -shared -fPIC -o libtest.so test.o
cp libtest.so ~/lib

gcc -o app app.o -L. -ltest

#export LD_LIBRARY_PATH=/usr/lib:/usr/local/lib:$HOME/lib
