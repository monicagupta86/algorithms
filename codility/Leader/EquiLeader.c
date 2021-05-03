https://app.codility.com/demo/results/trainingTKQVK6-G7X/

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int result = 0;
    int *stack = (int *)malloc(sizeof(int) * N);
    int top = -1;
    
    for (int i = 0; i < N - 1; i++) {
        stack[++top] = A[i];
        if (top > 1 && stack[top] != stack[top - 1]) top -= 2;
    }
    
    if (top == -1) {
        free(stack);
        return 0;
    }
        
    int candidate = stack[top];
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == candidate) count++;
    }
    if (count <= N / 2) {
        free(stack);
        return 0;
    }

    int lcount = 0;
    int rcount;
    
    for (int S = 0; S < N - 1; S++) {
        lcount += (A[S] == candidate ? 1 : 0);
        rcount = count - lcount;
        
        if ((lcount > (S + 1) / 2) && (rcount > (N - (S + 1)) / 2)) result++;
    }
    
    free(stack);
    return result;
}
