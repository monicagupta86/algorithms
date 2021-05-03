https://app.codility.com/demo/results/trainingM9MQCW-ENJ/

#include <string.h>

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int max = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] > max) max = A[i];
    }
    
    if (max != N) return 0;
    
    int wc = max / 32 + (max % 32 ? 1 : 0);
    int *words = (int *)malloc(sizeof(int) * wc);
    memset(words, 0, sizeof(int) * wc);
    
    int count = 0;
    for (int i = 0; i < N; i++) {
        int w = (A[i] - 1) / 32;
        int bit = 1 << ((A[i] - 1) % 32);
        if (words[w] & bit) return 0;
        else {
            words[w] |= bit;
            count++;
        }
    }
    
    return count == max;
}
