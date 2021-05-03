https://app.codility.com/demo/results/trainingUYXRT4-8K7/

int solution(int H[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int *stack = (int *)malloc(sizeof(int) * N);
    int top = -1;
    
    stack[++top] = H[0];
    int count = 0;
    for (int i = 1; i < N; i++) {
        if (H[i] > stack[top]) {
            stack[++top] = H[i];
        } else if (H[i] < stack[top]) {
            while (H[i] < stack[top]) {
                top--;
                count++;
            }
            if (H[i] > stack[top]) stack[++top] = H[i];
        }
    }
    
    free(stack);
    return count + top + 1;
}
