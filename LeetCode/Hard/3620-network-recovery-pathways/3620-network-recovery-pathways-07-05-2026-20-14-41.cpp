class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> graph(n);
        vector<int> deg(n);
        int left = std::numeric_limits<int>::max(), right = 0;

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (!(online[u] && online[v])) continue;
            graph[u].push_back({v, w});
            ++deg[v];
            left = min(left, w);
            right = max(right, w);
        }

        queue<int> q;
        for (int i = 1; i < n; ++i) {
            if (deg[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int u = q.front(); q.pop();

            for (const auto& [v, w] : graph[u]) {
                --deg[v];
                if (v && deg[v] == 0) q.push(v);
            }
        }

        auto check = [&](int mid) -> bool {
            vector<long long> dp(n, std::numeric_limits<long long>::max() >> 1);
            dp[0] = 0;
            vector<int> cDeg = deg;
            queue<int> q;
            q.push(0);

            while (!q.empty()) {
                int u = q.front(); q.pop();

                if (u == n - 1) return dp[u] <= k;
                
                for (const auto& [v, w] : graph[u]) {
                    if (w >= mid)
                        dp[v] = min(dp[v], dp[u] + w);

                    --cDeg[v];
                    if (cDeg[v] == 0) q.push(v);
                }

            }

            return false;
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