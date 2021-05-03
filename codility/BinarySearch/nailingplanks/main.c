int compNails(const void *a, const void *b) {
    int *A = (int *)a;
    int *B = (int *)b;
    
    if (A[0] == B[0]) return (A[1] - B[1]);
    return (A[0] - B[0]);
}

int getEarliestNail(int a, int b, int (*nails)[2], int M) {
    int lo = 0;
    int hi = M - 1;
    int pos = -1;
    
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int nailpos = nails[mid][0];
        if (nailpos < a) {
            lo = mid + 1;
        } else if (nailpos > b) {
            hi = mid - 1;
        } else {
            pos = mid;
            hi = mid - 1;
        }
    }
    
    if (pos == -1) return -1;
    int min = nails[pos][1];

    for (int i = pos + 1; i < M; i++) {
        if (nails[i][0] > b) break;
        
        if (min > nails[i][1]) min = nails[i][1];
    }
    

    return min;
}

int solution(int A[], int B[], int N, int C[], int M) {
    // write your code in C99 (gcc 6.2.0)
    int (*nails)[2] = (void *)malloc(sizeof(int) * 2 * M);
    for (int i = 0; i < M; i++) {
        nails[i][0] = C[i];
        nails[i][1] = i;
    }
    qsort(nails, M, sizeof(int) * 2, compNails);
    
    int j = 0;
    for (int i = 0; i < N; i++) {
        int min = getEarliestNail(A[i], B[i], nails, M);
        if (min == -1) {
            free(nails);
            return -1;
        }
        
        if (j < min) j = min;
        if (i == N - 1) {
            free(nails);
            return j + 1;
        }
    }
    
    return -1;
}
