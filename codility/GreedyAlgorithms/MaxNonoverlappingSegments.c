int solution(int A[], int B[], int N) {
    // write your code in C99 (gcc 6.2.0)
    
    if (N == 0) return 0;
    
    int count = 1;
    int i = 0;
    
    while (i < N) {
        int j = i + 1;
        while (j < N && A[j] <= B[i]) j++;
        if (j == N) break;

        i = j;        
        count++;
    }
    
    return count;
}
