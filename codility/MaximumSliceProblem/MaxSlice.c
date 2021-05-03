https://app.codility.com/demo/results/trainingGA8XFP-ZAS/

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int max = A[0];
    int sum = A[0];
    
    for (int i = 1; i < N; i++) {
        if (sum + A[i] < A[i]) {
            sum = A[i];
        } else {
            sum += A[i];
        }
        if (sum > max) max = sum;
    }
    
    return max;
}
