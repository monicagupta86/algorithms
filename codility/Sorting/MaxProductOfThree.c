https://app.codility.com/demo/results/trainingCRF8NY-ABB/

int comp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    qsort(A, N, sizeof(int), comp);
    
    int max1 = A[N - 1] * A[N - 2] * A[N - 3];
    int max2 = A[0] * A[1] * A[N - 1];
    
    if (max1 > max2) return max1;
    else return max2;
}
