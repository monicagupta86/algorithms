https://app.codility.com/c/run/trainingKN7EF5-334/

int solution(int A[], int B[], int N) {
    // write your code in C99 (gcc 6.2.0)
    
    if (N < 2) return N;
    
    int *stack = (int *)malloc(sizeof(int) * N);
    int top = -1;
    
    for (int i = 0; i < N; i++) {
        stack[++top] = i;
        if (B[i] == 0) { //upstream
            if (top > 0 && B[stack[top - 1]] == 1) { //last fish is downstream
                if (A[stack[top] - 1] > A[i]) {
                    top--;
                } else {
                    while (top > 0 && B[stack[top - 1]] == 1 && A[stack[top] - 1] < A[i]) {
                        stack[--top] = i;
                    }
                }
            }
        }
    }
    
    free(stack);
    return top + 1;
}
