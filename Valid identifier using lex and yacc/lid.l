%{
#include "y.tab.h"
extern int yylval;
%}

%%
[a-zA-Z]+ {yylval = atoi(yytext); return LET;}
[0-9]+ {yylval = atoi(yytext); return NUM;}
\n {return 0;}
. {return yytext[0];}
%%

int yywrap()
{
    return 1;
}