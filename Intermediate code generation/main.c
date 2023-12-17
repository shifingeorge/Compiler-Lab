#include<stdio.h>
#include<string.h>

// Declare variables to hold operator and arguments
char op[2], arg1[5], arg2[5], result[5];

void main() {
    // Declare file pointers
    FILE *fp1, *fp2;

    // Open input and output files
    fp1 = fopen("input.txt", "r");
    fp2 = fopen("output.txt", "w");

    // Loop until the end of the input file is reached
    while (!feof(fp1)) {
        // Read operator and arguments from input file
        fscanf(fp1, "%s%s%s%s", op, arg1, arg2, result);

        // Check the operator and perform corresponding operations
        if (strcmp(op, "+") == 0) {
            fprintf(fp2, "\nMOV R0, %s", arg1);
            fprintf(fp2, "\nADD R0, %s", arg2);
            fprintf(fp2, "\nMOV %s, R0", result);
        }
        else if (strcmp(op, "*") == 0) {
            fprintf(fp2, "\nMOV R0, %s", arg1);
            fprintf(fp2, "\nMUL R0, %s", arg2);
            fprintf(fp2, "\nMOV %s, R0", result);
        }
        else if (strcmp(op, "-") == 0) {
            fprintf(fp2, "\nMOV R0, %s", arg1);
            fprintf(fp2, "\nSUB R0, %s", arg2);
            fprintf(fp2, "\nMOV %s, R0", result);
        }
        else if (strcmp(op, "/") == 0) {
            fprintf(fp2, "\nMOV R0, %s", arg1);
            fprintf(fp2, "\nDIV R0, %s", arg2);
            fprintf(fp2, "\nMOV %s, R0", result);
        }
        else if (strcmp(op, "=") == 0) {
            fprintf(fp2, "\nMOV R0, %s", arg1);
            fprintf(fp2, "\nMOV %s, R0", result);
        }
    }

    // Close the files
    fclose(fp1);
    fclose(fp2);
}