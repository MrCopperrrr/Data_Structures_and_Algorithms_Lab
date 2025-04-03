int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int findLCM(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    return (a * b) / gcd(a, b);
}