%{
#include <stdio.h>  // Including standard I/O library for printf
%}

%%
[0-3][0-9]"/"[0-1][0-2]"/"[0-2][0-9][0-9][0-9] {
    // Pattern matching for DD/MM/YYYY format
    // Prints "Valid date" with the matched text when matched
    printf("Valid date: %s\n", yytext);
}
. {
    // Default case for any other input
    // Prints "Invalid date" for any input not matching the specified format
    printf("Invalid date\n");
}
%%

int yywrap() {
    // yywrap function required by Flex, returning 1 to signify end of input
    return 1;
}

int main() {
    // Main function initiating the program
    printf("Enter the date (DD/MM/YYYY format): ");
    yylex();  // Invoking lexical analyzer
    return 0; // Exiting the program
}