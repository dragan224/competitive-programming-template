string convertBase(long long number, int base) {
    if (number == 0) return "0";

    string ans;
    while (number > 0) {
        int mod = number % base;
        if (mod < 10) ans.push_back(mod + '0');
        else ans.push_back(mod - 10 + 'A');
        number /= base;
    }
    while (ans.size() > 1 && ans.back() == '0') {
        ans.pop_back();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}