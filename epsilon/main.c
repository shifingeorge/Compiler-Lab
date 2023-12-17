#include<stdio.h>
#include<string.h>

// Array to store the resulting states after transition
char result[20][20], copy[3], states[20][20];

// Function to add a state to the resulting set
void add_state(char a[3], int i) 
{
    strcpy(result[i], a); // Copies the state to the result set
}

// Function to display the resulting set
void display(int n) {
    int k = 0;
    printf("Epsilon closure of %s = { ", copy);
    while (k < n) {
        printf(" %s", result[k]); // Displays each state in the resulting set
        k++;
    }
    printf(" } \n");
}

int main() 
{
    FILE *INPUT;
    INPUT = fopen("input.dat", "r"); // Opens a file named "input.dat" in read mode

    char state[3]; // Stores the current state being processed
    int end, i = 0, n, k = 0;
    char state1[3], input[3], state2[3];

    printf("Enter the no of states: \n");
    scanf("%d", & n); // Reads the number of states from user input
    printf("Enter the states :\n");

    // Reads and stores the input states provided by the user
    for (k = 0; k < 4; k++) {
        scanf("%s", states[k]);
    }

    // Loop to process each state and find its epsilon closure
    for (k = 0; k < n; k++) {
        i = 0;
        strcpy(state, states[k]); // Copy the current state to be processed
        strcpy(copy, state); // Copy of the state for displaying purposes
        add_state(state, i++); // Add the initial state to the resulting set

        // Loop to find epsilon transitions of the current state
        while (1) {
            end = fscanf(INPUT, "%s%s%s", state1, input, state2); // Reads transitions from the file

            // Break loop if end of file (EOF) is reached
            if (end == EOF) {
                break;
            }

            // Checks if the current state matches the transition start state
            if (strcmp(state, state1) == 0) {
                // Checks if the transition input is epsilon ("e")
                if (strcmp(input, "e") == 0) {
                    add_state(state2, i++); // Adds the epsilon closure state to the resulting set
                    strcpy(state, state2); // Updates the current state to the epsilon closure state
                }
            }
        }
        display(i); // Display the epsilon closure set for the current state
        rewind(INPUT); // Reset file pointer to the beginning for the next state processing
    }
    return 0;
}
