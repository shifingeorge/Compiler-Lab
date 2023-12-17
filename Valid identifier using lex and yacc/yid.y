%{
#include<stdio.h>
%}

%token NUM LET

%%
E:LET T {printf("Valid Identifier\n"); return 0;}
T : LET NUM
|NUM LET
|LET
|NUM
|;
%%

int main()
{
    printf("Enter the text: ");
    yyparse();
}
int yyerror()
{
    printf("Invalid\n");
    return 0;
}