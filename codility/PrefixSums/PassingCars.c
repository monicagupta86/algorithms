https://app.codility.com/demo/results/training3V3SHK-DP7/

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int result = 0;
    int count0 = 0;
    
    for (int i = 0; i < N; i++) {
        if (A[i] == 0) {
            count0++;
        } else {
            result += (count0);
            if (result > 1000000000) return -1;
        }
    }
    
    return result;
}
