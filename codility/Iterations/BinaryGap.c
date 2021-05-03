// https://app.codility.com/demo/results/trainingJBHCBF-TNN/

int solution(int N) {
    // write your code in C99 (gcc 6.2.0)
    int start = 0;
    int max = 0;
    int count = 0;
    
    while (N) {
        if (start) {
            while (!(N & 0x01)) {
                count++;
                N >>= 1;
            }
        }
        if (N & 0x01) {
            if (count > max) max = count;
            start = 1;
            count = 0;
        }
        N >>= 1;
    }
    
    return max;
}
