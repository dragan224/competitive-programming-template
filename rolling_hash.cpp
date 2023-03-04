class RollingHash {
    public:
        RollingHash(string input) : pows(input.size() + 3), prefix(input.size() + 3), suffix(input.size() + 3) {
            pows[0] = 1;
            for (int i = 1; i < pows.size(); i++) {
                pows[i] = modmul(pows[i - 1], prime);
            }

            for (int i = 1; i <= input.size(); i++){
                prefix[i] = modmul(prefix[i - 1], prime) + input[i - 1] + 997;
                if (prefix[i] >= mod) prefix[i] -= mod;
            }

            for (int i = input.size(); i >= 1; i--){
                suffix[i] = modmul(suffix[i + 1], prime) + input[i - 1] + 997;
                if (suffix[i] >= mod) suffix[i] -= mod;
            }
        }

        uint64_t getForward(int from, int to){
            int64_t ans = prefix[to + 1] - modmul(pows[to - from + 1], prefix[from]);
            return ans < 0 ? ans + mod : ans;
        }

        uint64_t getReverse(int from, int to){
            int64_t ans = suffix[from + 1] - modmul(pows[to - from + 1], suffix[to + 2]);
            return ans < 0 ? ans + mod : ans;
        }

        uint64_t getHash(string input) {
            int64_t  ans = 0;
            for (int i = 0; i < input.size(); i++) {
                ans = modmul(ans, prime) + input[i] + 997;
                if (ans >= mod) ans -= mod;
            }
            return ans;
        }

    private:
        const uint64_t mod = (1ULL << 61) - 1;
        const int prime = 31337;
        vector<long long> pows;
        vector<long long> prefix, suffix;

        int64_t modmul(uint64_t a, uint64_t b) {
            uint64_t l1 = (uint32_t)a, h1 = a >> 32, l2 = (uint32_t)b, h2 = b >> 32;
            uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
            uint64_t ret = (l & mod) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
            ret = (ret & mod) + (ret >> 61);
            ret = (ret & mod) + (ret >> 61);
            return ret - 1;
        }
};