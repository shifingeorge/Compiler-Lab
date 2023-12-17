#include<stdio.h>

void main() {
    char stack[20], ip[20], opt[10][10][1], ter[10];
    int i, j, k, n, top = 0, col, row;

    // Initialize arrays
    for (i = 0; i < 10; i++) {
        stack[i] = NULL;
        ip[i] = NULL;
        for (j = 0; j < 10; j++) {
            opt[i][j][1] = NULL;
        }
    }

    // Input terminals
    printf("Enter the number of terminals: \n");
    scanf("%d", &n);
    printf("Enter the terminals: \n");
    scanf("%s", &ter);

    // Input table values
    printf("Enter the table values: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Enter the value for %c %c: ", ter[i], ter[j]);
            scanf("%s", opt[i][j]);
        }
    }

    // Display Operator Precedence Table
    printf("\n**** OPERATOR PRECEDENCE TABLE ****\n");
    for (i = 0; i < n; i++) {
        printf("\t%c", ter[i]);
    }
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("%c", ter[i]);
        for (j = 0; j < n; j++) {
            printf("\t%c", opt[i][j][0]);
        }
        printf("\n");
    }

    // Initialize stack
    stack[top] = '$';

    // Input string
    printf("\nEnter the input string: ");
    scanf("%s", ip);

    i = 0;

    // Display stack, input string, and actions
    printf("\nSTACK\t\t\tINPUT STRING\t\t\tACTION\n");
    printf("%s\t\t\t%s\t\t\t", stack, ip);

    while (i <= strlen(ip)) {
        // Get column and row indices
        for (k = 0; k < n; k++) {
            if (stack[top] == ter[k]) col = k;
            if (ip[i] == ter[k]) row = k;
        }

        if ((stack[top] == '$') && (ip[i] == '$')) {
            printf("String is accepted\n");
            break;
        } else if ((opt[col][row][0] == '<') || (opt[col][row][0] == '=')) {
            stack[++top] = opt[col][row][0];
            stack[++top] = ip[i];
            printf("Shift %c", ip[i]);
            i++;
        } else {
            if (opt[col][row][0] == '>') {
                while (stack[top] != '<') {
                    --top;
                }
                top = top - 1;
                printf("Reduce");
            } else {
                printf("\nString is not accepted");
                break;
            }
        }

        // Display stack and input string
        printf("\n");
        for (k = 0; k <= top; k++) {
            printf("%c", stack[k]);
        }
        printf("\t\t\t");
        for (k = i; k < strlen(ip); k++) {
            printf("%c", ip[k]);
        }
        printf("\t\t\t");
    }
}