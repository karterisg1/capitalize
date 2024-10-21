#include <stdio.h>

main() {    int   ch  ; ch   = getchar(  ) ; while ( ch !=   EOF ) { if   (ch >= 'a'   &&   ch <= 'z') ch = ch   -   ('a'  -  'A')  ; putchar(ch)  ; ch = getchar(); } }