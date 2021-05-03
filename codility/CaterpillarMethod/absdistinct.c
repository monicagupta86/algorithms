#include <math.h>

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)

    int i = 0;
    int j = N - 1;
    int count = 1;

    while (i < j) {
        long a = labs(A[i]);
        long b = labs(A[j]);

        if (a != b) {
            count++;
        }

        //printf("a %ld b %ld count %d\n", a, b, count);

        if (a <= b) {
            while (j > i && b == labs(A[j])) j--;
        } else {
            while (i < j && a == labs(A[i])) i++;
        }
    }

    return count;
}
