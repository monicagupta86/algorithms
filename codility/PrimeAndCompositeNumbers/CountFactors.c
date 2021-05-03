https://app.codility.com/demo/results/trainingYYBXRF-9CJ/

int solution(int N) {
    // write your code in C99 (gcc 6.2.0)
    int count = 0;
    long i;
    
    for (i = 1; i * i < N; i++) {
        if (N % i == 0) count += 2;
    }
    
    if (i * i == N) count += 1;
    
    return count;
}
