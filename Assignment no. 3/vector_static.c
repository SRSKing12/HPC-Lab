#include <stdio.h>
#include <omp.h>

#define VECTOR_SIZE 200

int main() {
    int vector[VECTOR_SIZE];
    int result[VECTOR_SIZE];
    int chunk_sizes[] = {1, 5, 10, 20, 50}; // Chunk sizes to test

    // Initialize the vector
    for (int i = 0; i < VECTOR_SIZE; i++) {
        vector[i] = i;
    }

    for (int i = 0; i < sizeof(chunk_sizes) / sizeof(chunk_sizes[0]); i++) {
        int chunk_size = chunk_sizes[i];
        double start_time, end_time;

        // Reset result
        for (int j = 0; j < VECTOR_SIZE; j++) {
            result[j] = 0;
        }

        // Parallel addition with static schedule and specified chunk size
        start_time = omp_get_wtime();
        #pragma omp parallel for schedule(static, chunk_size)
        for (int j = 0; j < VECTOR_SIZE; j++) {
            result[j] = vector[j] + 1; // Scalar addition
        }
        end_time = omp_get_wtime();

        // Calculate speedup
        double execution_time = end_time - start_time;

        printf("Chunk Size %d: Execution Time: %f seconds\n", chunk_size, execution_time);
    }

    return 0;
}
