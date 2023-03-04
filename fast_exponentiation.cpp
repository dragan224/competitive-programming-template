int pow(int base, int exponent, int modulo) {
    int ans = 1;
    for (int i = 0; i < 31; i++) {
        if (exponent & 1<<i) ans = 1LL * ans * base % modulo;
        base = 1LL * base * base % modulo;
    }
    return ans;
}

int inverse(int number, int mod) {
    return pow(number, mod - 2, mod);
}