# Compiler Lab Programs - Lex & Yacc

Welcome to the Compiler Lab Programs repository! This collection showcases Lex and Yacc programs for various tasks related to lexical analysis and parsing.

## Programs Overview
The repository showcases various compiler-related programs created using Lex and Yacc in c programming.

### Validating Input Patterns
- **Valid Date Checker:** Lex and Yacc programs to check if the input string is a valid date.
- **Email Validator:** Lex and Yacc programs for validating email addresses.
- **Mobile Number Validator:** Lex and Yacc programs to validate mobile numbers.
- **URL Validator:** Lex and Yacc programs to validate URLs.

### Calculator using Lex & Yacc
- **Arithmetic Calculator:** Lex and Yacc programs for basic arithmetic operations.

### String Operations
- **String Analyzer:** Lex and Yacc programs to perform string operations.
- **Valid Identifier Checker:** Lex and Yacc programs to verify valid identifiers.

### Lexical Analysis & Counting
- **Lexical Analyzer:** Lex program to analyze tokens in input strings.
- **Character, Lines, Spaces, Vowels Counter:** Lex program to count characters, lines, spaces, and vowels.

### To run the code on ubuntu
## Running Flex and Bison (Yacc) Programs on Ubuntu

### Prerequisites
Ensure that Flex and Bison (Yacc) are installed. If not installed, use the following commands:

```bash
sudo apt-get update
sudo apt-get install flex
sudo apt-get install bison
```

### To Run the lex and yacc
## Run Flex to generate the lexer code (lex.yy.c):
```bash
flex lexer.l
```

## Run Bison to generate the parser code (y.tab.c and y.tab.h):
```bash
yacc -d parser.y
```

## Compile the generated C files (lex.yy.c and y.tab.c) using GCC:
```bash
gcc lex.yy.c y.tab.c -o my_parser -lfl
```

## Run the generated parser executable:
```bash
./my_parser
```
