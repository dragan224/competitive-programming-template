void bfs(unordered_map<int, vector<int>>& graph, vector<int>& start) {
    queue<int> q;
    unordered_set<int> visited;

    for (auto node: start) {
        q.push(node);
        visited.insert(node);
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto neighbor: graph[node]) {
            if (visited.count(neighbor) > 0) continue;
            visited.insert(neighbor);
            q.push(neighbor);
        }
    }
}