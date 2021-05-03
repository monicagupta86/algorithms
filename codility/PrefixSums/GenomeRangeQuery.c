https://app.codility.com/demo/results/training7NHCYE-QPM/

struct Results solution(char *S, int P[], int Q[], int M) {
    struct Results result;
    // write your code in C99 (gcc 6.2.0)
    result.A = (int *)malloc(sizeof(int) * M);
    result.M = M;
    
    int N = strlen(S);
    
    int *Pa = (int *)malloc(sizeof(int) * (N + 1));
    int *Pc = (int *)malloc(sizeof(int) * (N + 1));
    int *Pg = (int *)malloc(sizeof(int) * (N + 1));

    Pa[0] = 0;
    Pc[0] = 0;
    Pg[0] = 0;
    
    for (int i = 0; i < N; i++) {
        Pa[i + 1] = Pa[i] + (S[i] == 'A' ? 1 : 0);
        Pc[i + 1] = Pc[i] + (S[i] == 'C' ? 1 : 0);
        Pg[i + 1] = Pg[i] + (S[i] == 'G' ? 1 : 0);
    }
    
    for (int i = 0; i < M; i++) {
        if (Pa[Q[i] + 1] - Pa[P[i]] > 0) {
            result.A[i] = 1;
        } else if (Pc[Q[i] + 1] - Pc[P[i]] > 0) {
            result.A[i] = 2;
        } else if (Pg[Q[i] + 1] - Pg[P[i]] > 0) {
            result.A[i] = 3;
        } else {
            result.A[i] = 4;
        }
    }
    
    return result;
}
