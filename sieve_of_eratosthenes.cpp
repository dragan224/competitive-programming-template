vector<int> sieve(int limit) {
    vector<bool> mark(limit + 1);
    for (int i = 2; i * i <= limit; i++) {
        if (mark[i]) continue;
        for (int j = i*2; j <= limit; j += i) {
            mark[j] = true;
        }
    }

    vector<int> ans;
    for (int i = 2; i <= limit; i++) {
        if (!mark[i]) ans.push_back(i);
    }
    return ans;
}