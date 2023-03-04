struct Edge {
    int node;
    long long distance;
    bool operator<(const Edge& other) const {
        return distance > other.distance;
    }
};

unordered_map<int, long long> dijkstra(unordered_map<int, vector<Edge>>& graph, vector<int> start) {
    priority_queue<Edge> pq;
    
    unordered_map<int, long long> ans;
    for (auto node: graph) {
        for (auto neighbor: node.second) {
            ans[neighbor.node] = -1;
        }
        ans[node.first] = -1;
    }

    for (auto node: start) {
        ans[node] = 0;
        pq.push({node, 0});
    }
    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();

        for (auto neighbor: graph[curr.node]) {
            long long dist = curr.distance + neighbor.distance;
            if (ans[neighbor.node] == -1 || dist < ans[neighbor.node]) {
                ans[neighbor.node] = dist;
                pq.push({neighbor.node, dist});
            }
        }
    }
    return ans;
}