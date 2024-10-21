#include <stdio.h>
#define PRINTDASH(X) do {int i; for(i=0;i<(X);i++) printf("-");} while(0)
main
( ){int
ch='{',i=';';int sq=0, dq = 0,
backslash=0, total=0, letters=0  ;
while((ch=getchar(
))!=EOF){total++;if(
(ch>='A' &&
ch <='Z') || (ch>='a'
&& ch <='z')) letters++; else {if(ch=='\'') sq++
;if(ch=='\"') dq++; if(ch=='\\') {backslash++;
}}}printf("%d characters input(\n contains {",
total);printf("%d \';",sq); printf("%d \";",dq); printf("%d \\"
,backslash);printf("}\n)\n");printf("+");PRINTDASH(21);printf("+\n");
printf("|"); for(i=0;i<(20*letters)/total;i++) { printf("*"); } do {printf(" ")
;} while(++i<21); printf("|\n"); printf("+"); PRINTDASH(21); printf ("+\n"); 
sq=12; 
					#define AA 4
}
