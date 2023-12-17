%{
#include <stdio.h>
%}

%token NUM
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

%%
E : T { printf("Result = %d\n", $$); return 0; }
T : T '+' T { $$ = $1 + $3; }
| T '-' T { $$ = $1 - $3; }
| T '*' T { $$ = $1 * $3; }
| T '/' T { $$ = $1 / $3; }
| T '%' T { $$ = $1 % $3; }
| '-' NUM { $$ = -$2; }
| '(' T ')' { $$ = $2; }
| NUM { $$ = $1; }
%%

int main() 
{
  printf("Enter the expression\n");
  yyparse();
}
int yyerror()
{
  printf("\nExpression is invalid\n");
  return 0;
}
