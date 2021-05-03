https://app.codility.com/demo/results/trainingYCWD6K-433/

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int max = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] > 0 && max < A[i]) max = A[i];
    }
    
    int wc = max / 32 + (max % 32 ? 1 : 0);
    int *words = (int *)malloc(sizeof(int) * wc);
    memset(words, 0, sizeof(int) * wc);
    
    for (int i = 0; i < N; i++) {
        if (A[i] > 0) {
            int w = (A[i] - 1) / 32;
            int bit = 1 << ((A[i] - 1) % 32);
            words[w] |= bit;
            if (max < A[i]) max = A[i];
        }
    }
    
    for (int i = 1; i <= max; i += 32) {
        int w = (i - 1) / 32;
        for (int j = 0; j < 32; j++) {
            int bit = 1 << j;
            if (!(words[w] & bit)) {
                return (w * 32 + j + 1);
            } 
        }
    }
    
    return max + 1;
}
