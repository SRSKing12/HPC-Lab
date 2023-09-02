#include <omp.h>
#include <stdio.h>

void main(){
    printf("Hello World\n");
    int threads;

    #pragma omp parallel
    {
        threads = omp_get_num_threads();
        printf("Hello from thread no. %d\n", omp_get_thread_num());
    }

    printf("\nNo. of threads used = %d", threads);
}

// gcc -fopenmp hello_world.c