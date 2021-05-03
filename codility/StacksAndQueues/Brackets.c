https://app.codility.com/demo/results/training4GADWF-H4Z/

int solution(char *S) {
    // write your code in C99 (gcc 6.2.0)
    int N = strlen(S);
    char *stack = (char *)malloc(sizeof(char) * N / 2);
    int top = -1;
    
    while (top * 2 < N && *S) {
        char ch = *S;
        switch (ch) {
            case '(':
            case '{':
            case '[':
                stack[++top] = ch;
                break;
            case ')':
                if (top < 0 || stack[top] != '(') {
                    free(stack);
                    return 0;
                }
                top--;
                break;
            case '}':
                if (top < 0 || stack[top] != '{') {
                    free(stack);
                    return 0;
                }
                top--;
                break;
            case ']':
                if (top < 0 || stack[top] != '[') {
                    free(stack);
                    return 0;
                }
                top--;
                break;
            default:
                free(stack);
                return 0;
        }
        S++;
    }
    
    free(stack);
    if (top == -1) return 1;
    return 0;
}
