#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

extern void saxpyASM(int n, float A, float* X, float* Y, float* Z);

void saxpy(int n, float A, float* X, float* Y, float* Z) {
    for (int i = 0; i < n; i++) {
        Z[i] = A * X[i] + Y[i];
    }
}

// Prints first 10 elements of the result vector
void printFirstTen(float* Z) {
    for (int i = 0; i < 10; i++) {
        printf("%f ", Z[i]);
    }
    printf("\n");
}

int main() {

    /*
    // ***** For debugging *****
    int n = 4; 
    float A = 2.0f; 

    // Initialize arrays with fixed values
    float X[4] = { 1.0f, 2.0f, 3.0f, 4.0f };
    float Y[4] = { 5.0f, 6.0f, 7.0f, 8.0f };
    float Z[4]; // Result array

    printf("Before calling saxpyASM\n");
    saxpyASM(n, A, X, Y, Z);
    printf("After calling saxpyASM\n");
    for (int i = 0; i < n; i++) {
        printf("%f ", Z[i]);
    }
    printf("\n");

    // ***** For debugging *****
    */
    
    // ***** Actual Code *****
    int powers[3]; // Array to hold the three powers
    float A;
    int n;

    // Prompt for powers
    printf("Enter three powers for the sizes of the vectors separated by spaces (e.g., 20 24 28): ");
    scanf_s("%d %d %d", &powers[0], &powers[1], &powers[2]);

    // Prompt for the value of A
    printf("Enter the value of A: ");
    scanf_s("%f", &A);

    for (int s = 0; s < sizeof(powers) / sizeof(powers[0]); s++) {
        n = 1 << powers[s]; // Compute size as 2^power
        float* X = (float*)malloc(n * sizeof(float));
        float* Y = (float*)malloc(n * sizeof(float));
        float* Z = (float*)malloc(n * sizeof(float));

        if (X == NULL || Y == NULL || Z == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            free(X); 
            free(Y);
            free(Z);
            return 1; // Exit if any allocation fails
        }

        // Initialize vectors with random values
        for (int i = 0; i < n; i++) {
            X[i] = (float)rand() / RAND_MAX;
            Y[i] = (float)rand() / RAND_MAX;
        }

        // Timing the SAXPY kernel
        clock_t start = clock();
        for (int i = 0; i < 30; i++) { // Run 30 times
            saxpy(n, A, X, Y, Z); // Change function call based on if using C version or ASM version
        }
        clock_t end = clock();
        double time_spent = (double)(end - start) / CLOCKS_PER_SEC / 30.0; // Average excution time of 30 runs

        printf("2^%d elements: Size = %d, Time = %f seconds\n", powers[s], n, time_spent);
        printFirstTen(Z);

        free(X);
        free(Y);
        free(Z);
    }

    return 0;
    // ***** Actual Code *****
}