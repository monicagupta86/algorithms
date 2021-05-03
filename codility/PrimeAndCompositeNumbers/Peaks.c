https://app.codility.com/demo/results/trainingE77WF3-S9T/

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    if (N < 3) return 0;
    
    int *peaks = (int *)malloc(sizeof(int) * N);
    peaks[0] = 0;
    for (int i = 1; i < N - 1; i++) {
        peaks[i] = peaks[i - 1];
        if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
            peaks[i]++;
        }
    }
    peaks[N - 1] = peaks[N - 2];
    
    if (peaks[N - 1] == 0) return 0;

    for (int blocks = N / 2; blocks >= 2; blocks--) {
        if (N % blocks != 0) continue;
        int blockSize = N / blocks;
        int end = 0;
        int block = 0;
        for (; block < blocks; block++) {
            if (peaks[((block + 1) * blockSize) - 1] <= end) break;
            end = peaks[((block + 1) * blockSize) - 1];
        }
        if (block == blocks) {
            free(peaks);
            //printf("blocks %d blockSize: %d success\n", blocks, blockSize);
            return blocks;
        }
        //printf("blocks %d blockSize: %d\n", blocks, blockSize);
    }
    
    free(peaks);
    return 1;
}
