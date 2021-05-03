https://app.codility.com/demo/results/training72Y4WT-5BC/

int solution(int N) {
    // write your code in C99 (gcc 6.2.0)
    int min = (2 * (N + 1));
    
    for (int i = 2; i * i <= N; i++) {
        if (N % i == 0) {
            int a = i;
            int b = N / i;
            int perimeter = 2 * (a + b);
            if (perimeter < min) min = perimeter;
        }
    }
    
    return min;
}
