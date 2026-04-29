class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, bool> visited(n);
        unordered_map<int, vector<int>> adj;

        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        function<bool(int)> dfs = [&](int node) -> bool {
            if (node == destination) return true;

            if (visited.contains(node)) return visited[node];

            if (adj[node].size() == 0) return false;
            visited[node] = false;

            for (int next : adj[node]) {
                if (!dfs(next)) return false;
            }

            visited[node] = true;

            return visited[node];
        };


        if (adj[destination].size() > 0) return false;
        return dfs(source);
    }
};