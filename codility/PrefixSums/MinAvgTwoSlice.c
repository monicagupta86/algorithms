https://app.codility.com/demo/results/trainingRBVF35-H9K/

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int sum = A[0] + A[1];
    float minavg = (float)sum / 2;

    if (N < 3) return 0;
    sum += A[2];
    float avg = (float)sum / 3;
    if (avg < minavg) minavg = avg;
    
    int idx = 0;
    for (int i = 1; i < N - 1; i++) {
        sum = A[i] + A[i + 1];
        avg = (float)sum / 2;
        if (avg < minavg) {
            minavg = avg;
            idx = i;
        }
        
        if (i < N - 2) {
            sum += A[i + 2];
            avg = (float)sum / 3;
            if (avg < minavg) {
                minavg = avg;
                idx = i;
            }
        }
    }
    
    return idx;
}
