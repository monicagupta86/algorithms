https://app.codility.com/demo/results/trainingPFRTQ5-SNH/

struct Results solution(int A[], int N, int K) {
    struct Results result;
    // write your code in C99 (gcc 6.2.0)
    
    result.A = (int *)malloc(sizeof(int) * N);
    result.N = N;
    
    if (N == 0) return result;

    K %= N;
    for (int i = 0, base = N - K; i < N; i++) {
        result.A[i] = A[(base + i) % N];
    }
    return result;
}
