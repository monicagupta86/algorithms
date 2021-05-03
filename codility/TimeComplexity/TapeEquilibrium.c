https://app.codility.com/demo/results/trainingS57NCD-GB5/

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int lsum = A[0];
    int rsum = 0;
    for (int i = 1; i < N; i++) rsum += A[i];
    int minsum = abs(lsum - rsum);
    
    for (int i = 2; i < N; i++) {
        lsum += A[i - 1];
        rsum -= A[i - 1];
        int sum = abs(lsum - rsum);
        if (sum < minsum) minsum = sum;
    }
    
    return minsum;
}
