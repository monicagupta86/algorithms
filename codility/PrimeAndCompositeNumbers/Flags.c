https://app.codility.com/demo/results/trainingTWYTUA-JMF/

#include <math.h>

int placeFlags(int *peaks, int totalPeaks, int K) {
    int count = 0;
    int lastFlag = -K;
    
    for (int i = 0; i < totalPeaks; i++) {
        if (lastFlag + K <= peaks[i]) {
            //printf("K %d place flag on %d\n", K, peaks[i]);
            lastFlag = peaks[i];
            count++;
            if (count == K) return count;
        }
    }
    
    return count;
}

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    if (N < 3) return 0;
    
    int max = 0;
    
    int totalPeaks = 0;
    for (int i = 1; i < N - 1; i++) {
        if (A[i] > A[i - 1] && A[i] > A[i + 1]) totalPeaks++;
    }
    
    int *peaks = (int *)malloc(sizeof(int) * totalPeaks);
    for (int i = 1, j = 0; i < N - 1; i++) {
        if (A[i] > A[i - 1] && A[i] > A[i + 1]) peaks[j++] = i;
    }
    
    int K = sqrt(N - 2) + 1;
    if (K > totalPeaks) K = totalPeaks;
    for (; K > max; K--) {
        int count = placeFlags(peaks, totalPeaks, K);
        //printf("K %d count %d\n", K, count);
        if (count > max) max = count;
        if (max == K) return max;
    }
    
    return max;
}
