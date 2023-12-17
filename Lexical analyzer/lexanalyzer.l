%{
#include<stdio.h>     // Including standard input/output library
#include<math.h>      // Including math library
#include<stdlib.h>    // Including standard library
%}

%%
"if"|"else"|"while"|"for"|"switch"|"case"|"break" { printf("Keyword: %s\n", yytext); }// Matching and printing keywords (if, else, while, for, switch, case, break)

[0-9]+ { printf("Number: %s\n", yytext); }   // Matching and printing numbers (one or more digits)

[a-zA-Z][a-zA-Z0-9_]* { printf("Identifier: %s\n", yytext); }// Matching and printing identifiers (starting with a letter, followed by letters, digits, or underscores)

"("|")"|"/" { printf("Separator: %s\n", yytext); }// Matching and printing separators (parentheses or slash)

[0-9]+\.[0-9]+ { printf("Floating Point: %s\n", yytext); }// Matching and printing floating-point numbers (digits followed by a dot and more digits)

. { printf("Invalid Character: %s\n", yytext); }// Handling and printing any other character (invalid)
%%

int yywrap()
{
    return 1;  // Indicating end of input
}

int main()
{
    printf("Enter anything: ");  // Prompting user to enter input
    yylex();  // Invoking lexical analyzer
    return 0; // Exiting the program
}
