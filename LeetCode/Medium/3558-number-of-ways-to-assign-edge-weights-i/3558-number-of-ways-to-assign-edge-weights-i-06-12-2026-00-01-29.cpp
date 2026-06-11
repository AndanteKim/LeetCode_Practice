class Solution {
    static constexpr int mod = 1e9 + 7;

    int qpow(int x, int y) {
        int res = 1;
        for (; y; y >>= 1) {
            if (y & 1) res = 1ll * res * x % mod;
            x = 1ll * x * x % mod;
        }

        return res;
    }

    int dfs(vector<vector<int>>& g, int x, int f) {
        int maxDep = 0;
        for (auto& y : g[x]) {
            if (y == f) continue;
            maxDep = max(maxDep, dfs(g, y, x) + 1);
        }

        return maxDep;
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> g(n + 1);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }

        int maxDep = dfs(g, 1, 0);
        return qpow(2, maxDep - 1);
    }
};