#include<stdio.h>
#include<string.h>
#include<ctype.h>

// Structure to store expressions
struct expr {
    char op[2], op1[5], op2[5], res[5];
    int flag; // Flag to mark if optimization is done
} arr[10];

int n;

// Function prototypes
void input();
void output();
void change(int p, char *res);
void constant();

// Main function
void main() {
    input();    // Take user input
    constant(); // Perform constant folding optimization
    output();   // Display optimized code
}

// Function to take user input for expressions
void input() {
    int i;
    printf("\n\nEnter the maximum number of expressions: ");
    scanf("%d", &n);
    printf("\nEnter the input:\n");
    for (i = 0; i < n; i++) {
        scanf("%s", arr[i].op);
        scanf("%s", arr[i].op1);
        scanf("%s", arr[i].op2);
        scanf("%s", arr[i].res);
        arr[i].flag = 0; // Initialize flag
    }
}

// Function to perform constant folding optimization
void constant() {
    int i;
    int op1, op2, res;
    char op, res1[5];
    for (i = 0; i < n; i++) {
        if (isdigit(arr[i].op1[0]) && isdigit(arr[i].op2[0]) || strcmp(arr[i].op, "=") == 0) {
            op1 = atoi(arr[i].op1); // Convert op1 to integer
            op2 = atoi(arr[i].op2); // Convert op2 to integer
            op = arr[i].op[0]; // Get operator

            // Perform operation based on the operator
            switch (op) {
                case '+':
                    res = op1 + op2;
                    break;
                case '-':
                    res = op1 - op2;
                    break;
                case '*':
                    res = op1 * op2;
                    break;
                case '/':
                    res = op1 / op2;
                    break;
                case '=':
                    res = op1;
                    break;
            }

            sprintf(res1, "%d", res); // Convert result back to string
            arr[i].flag = 1; // Mark optimization done
            change(i, res1); // Update other expressions using the result
        }
    }
}

// Function to display optimized code
void output() {
    int i = 0;
    printf("\nOptimized code is:\n");
    for (i = 0; i < n; i++) {
        if (!arr[i].flag) {
            printf("%s %s %s %s\n", arr[i].op, arr[i].op1, arr[i].op2, arr[i].res);
        }
    }
}

// Function to update expressions with optimized result
void change(int p, char *res) {
    int i;
    for (i = p + 1; i < n; i++) {
        if (strcmp(arr[p].res, arr[i].op1) == 0) {
            strcpy(arr[i].op1, res); // Update op1 with optimized result
        }
        else if (strcmp(arr[p].res, arr[i].op2) == 0) {
            strcpy(arr[i].op2, res); // Update op2 with optimized result
        }
    }
}
