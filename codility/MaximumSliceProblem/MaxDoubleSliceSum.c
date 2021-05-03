https://app.codility.com/demo/results/trainingUT94FE-2UV/

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int *fwd = (int *)malloc(sizeof(int) * N);
    int *rev = (int *)malloc(sizeof(int) * N);
    
    fwd[0] = fwd[1] = 0;
    rev[N - 1] = rev[N - 2] = 0;
    
    for (int i = 2; i < N; i++) {
        fwd[i] = (fwd[i - 1] + A[i - 1]) > 0 ? fwd[i - 1] + A[i - 1] : 0;
        rev[N - i - 1] = (rev[N - i] + A[N - i]) > 0 ? rev[N - i] + A[N - i] : 0;
    }
    
    int max = fwd[1] + rev[1];
    for (int i = 2; i < N - 1; i++) {
        int sum = fwd[i] + rev[i];
        if (sum > max) max = sum;
    }
    
    free(fwd);
    free(rev);
    return max;
}
