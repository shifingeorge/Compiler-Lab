%{
#include <stdio.h>
int lc = 0, sc = 0, wc = 0, cc = 0; // Initializing counters for lines, spaces, words, and characters
%}

%%
[\n] { lc++; } // Counting newlines as lines and characters
[ ] { sc++; cc++; } // Counting spaces as spaces and characters
[^\t\n ]+ { // Counting words (non-space, non-tab, non-newline sequences)
    wc++; // Incrementing word count
    cc += yyleng; // Adding the length of the matched word to the character count
}

%%

int main()
{
    printf("Enter string: \n"); // Prompting user to enter input
    yylex(); // Invoking the lexical analyzer
    printf("Number of lines: %d\n", lc); // Displaying the count of lines
    printf("Number of spaces: %d\n", sc); // Displaying the count of spaces
    printf("Number of words: %d\n", wc); // Displaying the count of words
    printf("Number of characters: %d\n", cc); // Displaying the count of characters
    return 0; // Exiting the program
}

int yywrap()
{
    return 1; // Indicating the end of input
}
