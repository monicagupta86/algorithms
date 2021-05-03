https://app.codility.com/demo/results/trainingJ2PTHR-ZEZ/

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    
    long result = ((long)(N + 1) * (N + 2)) / 2;

    for (int i = 0; i < N; i++) {
        result -= (long)A[i];
    }
    
    return (int)result;
}
