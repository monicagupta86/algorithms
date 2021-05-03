https://app.codility.com/programmers/lessons/5-prefix_sums/

int solution(int A, int B, int K) {
    // write your code in C99 (gcc 6.2.0)
    int start = A % K == 0 ? A : A + (K - A % K);
    int end = B - (B % K);
    if (end < start) return 0;
    
    return ((end - start) / K) + 1;
}
