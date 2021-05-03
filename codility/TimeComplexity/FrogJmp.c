https://app.codility.com/demo/results/trainingN669GJ-S4F/

int solution(int X, int Y, int D) {
    // write your code in C99 (gcc 6.2.0)
    return ((Y - X) / D) + ((Y - X) % D ? 1 : 0);
}
