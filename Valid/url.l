%{
#include <stdio.h>
%}

%%
"http://www."[a-z]+".com"   { printf("Valid URL: %s\n", yytext); }
"http://www."[a-z]+".in"   { printf("Valid URL: %s\n", yytext); }
.                                { printf("Invalid URL\n"); }
%%

int main() 
{
    printf("Enter a string: \n");
    yylex();
    return 0;
}

int yywrap() 
{
    return 1;
}
