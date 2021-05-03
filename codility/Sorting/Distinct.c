https://app.codility.com/programmers/lessons/6-sorting/

int comp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    
    if (N < 2) return N;

    qsort(A, N, sizeof(int), comp);
    int distinct = 1;
    for (int i = 1; i < N; i++) {
        if (A[i] != A[i - 1]) distinct++;
    }
    
    return distinct;
}
