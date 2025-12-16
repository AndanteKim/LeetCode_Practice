class Solution {
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        unordered_map<int, vector<int>> g(n);

        for (const auto& h : hierarchy) {
            int u = h[0] - 1, v = h[1] - 1;
            g[u].push_back(v);
        }

        auto dfs = [&](auto&& self,
                       int u) -> tuple<vector<int>, vector<int>, int> {
            // dCost: discounted cost
            int cost = present[u], dCost = present[u] >> 1;

            // dp[u][state][budget]
            // state = 0: Don't purchase parent node, state = 1: Must purchase
            // parent node
            auto dp0 = vector(budget + 1, 0), dp1 = vector(budget + 1, 0);

            // subProfit[state][budget]
            // state = 0: discount not available, state = 1: discount available
            auto subProfit0 = vector(budget + 1, 0), subProfit1 = vector(budget + 1, 0);
            
            int uSize = cost;

            for (auto v : g[u]) {
                auto [subDp0, subDp1, vSize] = self(self, v);
                uSize += vSize;
                for (int i = budget; i >= 0; --i) {
                    for (int sub = 0; sub <= min(vSize, i); ++sub) {
                        subProfit0[i] = max(subProfit0[i],
                                            subProfit0[i - sub] + subDp0[sub]);
                        subProfit1[i] = max(subProfit1[i],
                                            subProfit1[i - sub] + subDp1[sub]);
                    }
                }
            }

            for (int i = 0; i <= budget; ++i) {
                dp0[i] = dp1[i] = subProfit0[i];

                if (i >= dCost) {
                    dp1[i] = max(subProfit0[i],
                                 subProfit1[i - dCost] + future[u] - dCost);
                }

                if (i >= cost) {
                    dp0[i] = max(subProfit0[i],
                                 subProfit1[i - cost] + future[u] - cost);
                }
            }

            return {dp0, dp1, uSize};
        };

        return std::get<0>(dfs(dfs, 0))[budget];
    }
};