https://app.codility.com/demo/results/trainingATKHED-FGU/

#include <string.h>

typedef struct {
    int divisors;
    int freq;
} number_t;

struct Results solution(int A[], int N) {
    struct Results result;
    // write your code in C99 (gcc 6.2.0)
    result.C = (int *)malloc(sizeof(int) * N);
    result.L = N;
    
    int max = 1;
    for (int i = 0; i < N; i++) {
        if (A[i] > max) max = A[i];
    }
    
    number_t *numbers = (number_t *)malloc(sizeof(number_t) * (max + 1));
    memset(numbers, 0, sizeof(number_t) * (max + 1));
    for (int i = 0; i < N; i++) {
        numbers[A[i]].freq++;
        numbers[A[i]].divisors = -1;
    }
    
    for (int i = 0; i < N; i++) {
        if (numbers[A[i]].divisors == -1) {
            numbers[A[i]].divisors = 0;
            int j = 1;
            for (; j * j < A[i]; j++) {
                if (A[i] % j == 0) {
                    numbers[A[i]].divisors += numbers[j].freq;
                    numbers[A[i]].divisors += numbers[A[i] / j].freq;
                }
            }
            if (j * j == A[i]) {
                numbers[A[i]].divisors += numbers[j].freq;
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        result.C[i] = N - numbers[A[i]].divisors;
    }
    
    free(numbers);
    return result;
}
