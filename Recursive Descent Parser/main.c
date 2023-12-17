#include<stdio.h>
#include<string.h>
#include<ctype.h>

char input[10]; // Array to store the input expression
int i, error; // Variables for tracking position and error

void E(); // Function to handle expressions
void T(); // Function to handle terms
void Eprime(); // Function to handle E' (E prime)
void Tprime(); // Function to handle T' (T prime)
void F(); // Function to handle factors

void main() {
    i = 0; // Initializing the position in input
    error = 0; // Flag to indicate errors

    printf("Enter an arithmetic expression: "); // Asking for user input
    gets(input); // Getting the input expression from the user

    E(); // Start parsing from the expression
    if (strlen(input) == i && error == 0) // Check if the entire input is parsed and no errors occurred
        printf("\nAccepted..!!!\n"); // Expression is accepted
    else
        printf("\nRejected..!!!\n"); // Expression is rejected
}

// Function to handle E -> TE'
void E() {
    T(); // Call function to handle term
    Eprime(); // Call function to handle E'
}

// Function to handle E' -> +TE' | ε
void Eprime() {
    if (input[i] == '+') { // If current character is '+'
        i++; // Move to the next character in input
        T(); // Call function to handle term
        Eprime(); // Call E' recursively
    }
}

// Function to handle T -> FT'
void T() {
    F(); // Call function to handle factor
    Tprime(); // Call function to handle T'
}

// Function to handle T' -> *FT' | ε
void Tprime() {
    if (input[i] == '*') { // If current character is '*'
        i++; // Move to the next character in input
        F(); // Call function to handle factor
        Tprime(); // Call T' recursively
    }
}

// Function to handle F -> id | (E)
void F() {
    if (isalnum(input[i])) // If current character is alphanumeric (letter or digit)
        i++; // Move to the next character in input
    else if (input[i] == '(') { // If current character is '('
        i++; // Move to the next character in input
        E(); // Call function to handle expression inside parentheses
        if (input[i] == ')') // If current character is ')'
            i++; // Move to the next character in input
        else
            error = 1; // Set error flag if ')' is missing
    } else {
        error = 1; // Set error flag for invalid input
    }
}
