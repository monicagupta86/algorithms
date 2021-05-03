int comp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);    
}

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    qsort(A, N, sizeof(int), comp);
    
    int count = 0;
    for (int p = 0; p < N - 2; p++) {
        int q = p + 1;
        int r = p + 2;
        while (r < N) {
            if (A[p] + A[q] > A[r]) {
                count += r - q;
                r++;
            } else if (q < r - 1) {
                q++;
            } else {
                r++;
                q++;
            }
        }
    }
    
    return count;
}
