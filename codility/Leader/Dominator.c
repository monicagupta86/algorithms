https://app.codility.com/demo/results/trainingZPQ87D-THC/

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    if (N < 2) return N - 1;
    int *stack = (int *)malloc(sizeof(int) * N);
    int top = -1;
    
    for (int i = 0; i < N; i++) {
        stack[++top] = A[i];
        if (top > 1 && stack[top] != stack[top - 1]) {
            top -= 2;
        }
    }
    
    int candidate = stack[top];
    int count = 0;
    int idx = -1;
    for (int i = 0; i < N; i++) {
        if (A[i] == candidate) {
            count++;
            idx = i;
        }
    }
    
    if (count > N / 2) {
        return idx;
    }
    
    return -1;
}
