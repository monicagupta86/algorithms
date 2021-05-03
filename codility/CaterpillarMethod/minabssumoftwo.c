int comp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);    
}

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int i = 0;
    int j = N - 1;
    
    qsort(A, N, sizeof(int), comp);
    int minsum = abs(A[i] + A[j]);
    
    while (i <= j) {
        int sum = A[i] + A[j];
        if (sum == 0) return 0;
        minsum = minsum < abs(sum) ? minsum : abs(sum);
        
        if (sum < 0) i++;
        else j--;
    }
    
    return minsum;
}
