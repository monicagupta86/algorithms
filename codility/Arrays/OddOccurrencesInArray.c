https://app.codility.com/demo/results/trainingHNSMS2-BQM/

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int result = 0;
    
    for (int i = 0; i < N; i++) {
        result ^= A[i];
    }
    
    return result;
}
