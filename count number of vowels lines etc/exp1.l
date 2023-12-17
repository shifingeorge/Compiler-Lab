%{
#include<stdio.h>
int vow = 0;
int con = 0;    
%}

%%
[aeiouAEIOU] {vow++;}
[a-zA-Z] {con++;}
%%

int yywrap()
{
    return 1;
}
main()
{
    printf("Enter the string: ");
    yylex();
    printf("Vowels: %d\nConsonants: %d\n",vow,con);
}