int solution(int K, int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int sum = 0;
    int count = 0;
    
    for (int i = 0; i < N; i++) {
        if (sum + A[i] >= K) {
            count++;
            sum = 0;
        } else {
            sum += A[i];
        }
    }
    
    return count;
}
