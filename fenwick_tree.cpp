class FenwickTree {
    public:
        FenwickTree(int size) : data(size + 1) {}
        void update(int index, long long value) {
            ++index;
            for (int i = index; i < data.size(); i += i & -i) {
                data[i] += value;
            }
        }

        long long query(int index) {
            ++index;
            long long ans = 0;
            for (int i = index; i; i -= i & -i) {
                ans += data[i];
            }
            return ans;
        }

        long long query(int from, int to) {
            return from == 0 ? query(to) : query(to) - query(from - 1);
        }
    private:
        vector<long long> data;
};