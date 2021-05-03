https://app.codility.com/demo/results/trainingUVHX85-72U/

#include <string.h>

#define NONPRIME 0
#define PRIME 1
#define SEMIPRIME 100

struct Results solution(int N, int P[], int Q[], int M) {
    struct Results result;
    // write your code in C99 (gcc 6.2.0)
    result.A = (int *)malloc(sizeof(int) * M);
    result.M = M;

    // Find max range
    int max = 1;    
    for (int i = 0; i < M; i++) {
        if (Q[i] > max) max = Q[i];
    }
    
    // Prepare sieve - mark all numbers as PRIME initially
    int *sieve = (int *)malloc(sizeof(int) * (max + 1));
    sieve[0] = sieve[1] = NONPRIME;
    for (int i = 2; i <= max; i++) {
        sieve[i] = PRIME;
    }

    // Mark out composite numbers
    for (int i = 2; i * i <= max; i++) {
        if (sieve[i] == PRIME) {
            for (int k = i * i; k <= max; k += i) {
                sieve[k] = NONPRIME;   
            }
        }
    }
    
    // Mark out semiprimes
    for (int i = 2; i * i <= max; i++) {
        if (sieve[i] != PRIME) continue;
        for (int k = i; i * k <= max; k++) {
            if (sieve[k] != PRIME) continue;
            sieve[i * k] = SEMIPRIME; // mark semiprime
        }
    }

    // Cumulate values of semiprimes at each index
    for (int i = 2; i <= max; i++) {
        sieve[i] = sieve[i - 1] + (sieve[i] == SEMIPRIME ? 1 : 0);
    }
    
    for (int i = 0; i < M; i++) {
        result.A[i] = sieve[Q[i]] - sieve[P[i] - 1];
    }
    
    return result;
}
