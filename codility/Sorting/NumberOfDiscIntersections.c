https://app.codility.com/demo/results/training3DB5QY-5YR/

typedef struct {
    long x, y;
} disc_t;

int comp(const void *a, const void *b) {
    int c = ((disc_t *)a)->x - ((disc_t *)b)->x;
    if (c == 0) {
        c = ((disc_t *)a)->y - ((disc_t *)b)->y;
    }
    return c;
}

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    if (N == 0) return 0;
    
    disc_t *discs = (disc_t *)malloc(sizeof(disc_t) * N);
    for (int i = 0; i < N; i++) {
        discs[i].x = (long)i - A[i];
        discs[i].y = (long)i + A[i];
    }
    
    qsort(discs, N, sizeof(disc_t), comp);
    
    int count = 0;
    for (int i = 0; i < N - 1; i++) {
        long end = discs[i].y;
        int j = i + 1;
        while (j < N && discs[j++].x <= end) {
            count++;
            if (count > 10000000) return -1;
        }
    }
    return count;
}
