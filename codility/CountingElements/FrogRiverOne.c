https://app.codility.com/demo/results/training7A9AHK-E2X/

#include <string.h>

int solution(int X, int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int wc = X / 32 + (X % 32 ? 1 : 0);
    int *words = (int *)malloc(sizeof(int) * wc);
    memset(words, 0, sizeof(int) * wc);
    int count = 0;
    
    for (int i = 0; i < N; i++) {
        int w = (A[i] - 1) / 32;
        int bit = 1 << ((A[i] - 1) % 32);
        if (!(words[w] & bit)) {
            words[w] |= bit;
            count++;
            if (count == X) return i;
        }
    }
    
    return -1;
}
