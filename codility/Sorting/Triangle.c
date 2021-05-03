https://app.codility.com/demo/results/trainingEWAD8F-4RF/

int comp(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;
    if (x > y) return 1;
    else if (x < y) return -1;
    else return 0;
}

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    if (N < 3) return 0;
    qsort(A, N, sizeof(int), comp);
    for (int i = 0; i < N - 2; i++) {
        if ((long)A[i] + A[i + 1] > (long)A[i + 2]) return 1;
    }
    
    return 0;
}
