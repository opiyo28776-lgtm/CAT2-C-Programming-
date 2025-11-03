/*
Name Prince Opiyo
Reg no PA106/G/28776/25
Description calculation for gross pay taxes and net pay
*/#include <stdio.h>
#include <stdlib.h> // For exit()

void display_file_contents(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file for display");
        return;
    }

    printf("\n--- Contents of %s ---\n", filename);
    int c;
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }
    fclose(file);
    printf("------------------------\n");
}

int main() {
    FILE *inputFile, *outputFile;
    int numbers[10];
    int i, sum = 0;
    double average;

    // 1. Prompt for input and store in "input.txt"
    inputFile = fopen("input.txt", "w");
    if (inputFile == NULL) {
        perror("Error opening input.txt for writing");
        return 1;
    }

    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++) {
        printf("Enter integer %d: ", i + 1);
        if (scanf("%d", &numbers[i]) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            // Clear invalid input from buffer
            while (getchar() != '\n');
            i--; // Decrement i to re-prompt for the same number
            continue;
        }
        fprintf(inputFile, "%d\n", numbers[i]);
    }
    fclose(inputFile);
    printf("Integers saved to input.txt\n");

    // 2. Read from "input.txt", calculate sum and average, write to "output.txt"
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        perror("Error opening input.txt for reading");
        return 1;
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        perror("Error opening output.txt for writing");
        fclose(inputFile); // Close input file before exiting
        return 1;
    }

    sum = 0;
    int count = 0;
    int num;
    while (fscanf(inputFile, "%d", &num) == 1) {
        sum += num;
        count++;
    }

    if (count > 0) {
        average = (double)sum / count;
        fprintf(outputFile, "Sum: %d\n", sum);
        fprintf(outputFile, "Average: %.2f\n", average);
    } else {
        fprintf(outputFile, "No numbers found in input.txt\n");
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("Sum and average calculated and saved to output.txt\n");

    // 3. Display contents of both files
    display_file_contents("input.txt");
    display_file_contents("output.txt");

    return 0;
}
