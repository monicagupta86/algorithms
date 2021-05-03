https://app.codility.com/demo/results/trainingA5Y5MH-PDY/

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    if (N == 0) return 0;
    
    int max_profit = 0;
    int min = A[0];

    for (int i = 1; i < N; i++) {
        if (A[i] > min) {
            int profit = A[i] - min;
            if (profit > max_profit) max_profit = profit;
        } else {
            min = A[i];
        }
    }
    
    return max_profit;
}
