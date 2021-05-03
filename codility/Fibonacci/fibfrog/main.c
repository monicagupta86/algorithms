#include <string.h>

typedef struct {
    int pos;
    int cost;
} node_t;

int *fib;
int fibSize;

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    //Initializa Queue
    
    if (N < 3) return 1;
    
    node_t *queue = (node_t *)malloc(sizeof(node_t) * N);
    memset(queue, 0, sizeof(node_t) * N);
    int first = 0;
    int last = 0;
    int qsize = 0;

    int *visited = (int *)malloc(sizeof(int) * N);
    memset(visited, 0, sizeof(int) * N);
    
    fib = (int *)malloc(sizeof(int) * N);
    fib[0] = 0;
    fib[1] = 1;
    fibSize = 2;
    for (int i = 2; ; i++) {
        int sum = fib[i - 1] + fib[i - 2];
        if (sum > N) {
            break;
        }
        fib[i] = sum;
        fibSize++;
        
        if (qsize == 0) {
            if (A[fib[i] - 1] == 1) {
                queue[last].pos = fib[i] - 1;
                queue[last].cost = 1;
                qsize = 1;
                visited[fib[i] - 1] = 1;
            } else if (fib[i] == N + 1) {
                free(fib);
                free(queue);
                return 1;
            }
        }
    }
    
    while (qsize > 0) {
        int cur_pos = queue[first].pos;
        int cur_cost = queue[first].cost;
        first = (first + 1) % N;
        qsize--;
        
        for (int f = 1; f < fibSize; f++) {
            int pos = cur_pos + fib[f];
            if (pos == N) {
                return cur_cost + 1;
            } else if (pos < N && !visited[pos] && A[pos] == 1) {
                last = (last + 1) % N;
                queue[last].pos = pos;
                queue[last].cost = cur_cost + 1;
                qsize++;
                visited[pos] = 1;
            }
        }
    }
    
    return -1;
}
