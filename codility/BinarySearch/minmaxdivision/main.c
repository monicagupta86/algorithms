int check(int A[], int N, int K, int midSum) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i];
        if (sum > midSum) {
            K--;
            if (!K) return 0;
            sum = A[i];
        }
    }
    return 1;
}

int solution(int K, int M, int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    
    int minSum = 0;
    int maxSum = 0;
    int midSum = 0;

    for (int i = 0; i < N; i++) {
        maxSum += A[i];
        minSum = minSum > A[i] ? minSum : A[i];
    }
    int res = maxSum;
    
    while (minSum <= maxSum) {
        midSum = (minSum + maxSum) / 2;
     
        if (check(A, N, K, midSum)) {
            maxSum = midSum - 1;
            res = midSum;
        } else {
            minSum = midSum + 1;
        }
    }
    
    return res;
}
