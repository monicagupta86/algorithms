#include <string.h>

#define MAX 1000000000
#define INC(n) total += n; if (total > MAX) return MAX;

int solution(int M, int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int wc = (M + 1) / 32 + ((M + 1) % 32 ? 1 : 0);
    int *words = (int *)malloc(sizeof(int) * wc);
    
    int total = 0;
    memset(words, 0, sizeof(int) * wc);
    int back = 0;
    
    for (int i = 0; i < N; i++) {
        int w = A[i] / 32;
        int bit = 1 << (A[i] % 32);
        if (words[w] & bit) {
            while (A[back] != A[i]) {
                int w = A[back] / 32;
                int bit = 1 << (A[back] % 32);
                words[w] &= ~bit;
                back++;
            }
            int w = A[back] / 32;
            int bit = 1 << (A[back] % 32);
            words[w] &= ~bit;
            back++;
        }

        words[w] |= bit;
        INC(i - back + 1)
    }
    
    return total;
}
