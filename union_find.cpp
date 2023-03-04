class UnionFind {
    public:
        UnionFind() : nodeToParent() {}

        bool add(int u, int v) {
            int uParent = find(u);
            int vParent = find(v);
            if (uParent == vParent) return false;

            setParent(u, uParent);
            setParent(v, uParent);
            return true;
        }

        int find(int node) {
            if (nodeToParent.count(node) == 0) {
                return node;
            }

            while (nodeToParent[node] != node) {
                node = nodeToParent[node];
            }
            return node;
        }
    private:
        void setParent(int node, int parent) {
            if (nodeToParent.count(node) == 0) {
                nodeToParent[node] = parent;
                return;
            }

            while (nodeToParent[node] != parent) {
                int temp = nodeToParent[node];
                nodeToParent[node] = parent;
                node = temp;
            }
        }

        unordered_map<int, int> nodeToParent;
};