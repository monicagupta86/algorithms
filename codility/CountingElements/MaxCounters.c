https://app.codility.com/demo/results/training2NF7VJ-NA3/

#include <string.h>

struct Results solution(int N, int A[], int M) {
    struct Results result;
    // write your code in C99 (gcc 6.2.0)
    result.C = (int *)malloc(sizeof(int) * N);
    memset(result.C, 0, sizeof(int) * N);
    result.L = N;
    int max = 0;
    int base = 0;
    
    for (int i = 0; i < M; i++) {
        if (A[i] <= N) {
            if (result.C[A[i] - 1] < base) {
                result.C[A[i] - 1] = base + 1;
            } else {
                 result.C[A[i] - 1]++;
            }
            if (result.C[A[i] - 1] > max) max = result.C[A[i] - 1];
        } else {
            base = max;
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (result.C[i] < base) result.C[i] = base;
    }
    return result;
}
