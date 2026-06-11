class Solution {
private:
    int dfs(vector<vector<int>>& graph, int x, int f) {
        int maxDep = 0;
        for (int y : graph[x]) {
            if (y == f) continue;
        
            maxDep = max(maxDep, dfs(graph, y, x) + 1);
        }

        return maxDep;
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector graph(n + 1, vector<int>{});

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int maxDep = dfs(graph, 1, 0), mod = 1'000'000'007;
        long long ans = 1;

        for (int i = 0; i < maxDep - 1; ++i) ans = (ans << 1) % mod;

        return static_cast<int>(ans);
    }
};