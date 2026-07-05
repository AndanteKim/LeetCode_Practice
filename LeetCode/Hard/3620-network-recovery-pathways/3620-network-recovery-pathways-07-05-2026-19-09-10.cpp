class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> graph(n);
        int left = std::numeric_limits<int>::max(), right = 0;

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (!(online[u] && online[v])) continue;
            graph[u].push_back({v, w});
            left = min(left, w);
            right = max(right, w);
        }

        auto check = [&](int mid) -> int {
            vector<long long> memo(n, -1);
            auto dfs = [&](this auto&& dfs, int u) -> long long {
                if (u == n - 1) return 0;
                if (memo[u] != -1) return memo[u];
            
                long long ans = std::numeric_limits<long long>::max() >> 1;
                for (const auto& [v, w] : graph[u]) {
                    if (w >= mid) ans = min(ans, dfs(v) + w);
                }

                return memo[u] = ans;
            };

            return dfs(0) <= k;
        };

        if (!check(left)) return -1;

        while (left <= right) {
            int mid = left + ((right - left) >> 1);

            if (check(mid)) left = mid + 1;
            else right = mid - 1;
        }

        return right;
    }
};