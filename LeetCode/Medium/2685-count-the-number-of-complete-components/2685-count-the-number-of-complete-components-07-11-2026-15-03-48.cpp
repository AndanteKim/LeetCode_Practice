class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);

        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int completedComponent = 0;
        unordered_set<int> visited;
        
        auto dfs = [&](auto&& self, int curr, pair<int, int>& info) -> void {
            visited.insert(curr);
            ++info.first;
            info.second += graph[curr].size();

            for (int next : graph[curr]) {
                if (!visited.contains(next))
                    self(self, next, info);
            }
        };
        
        for (int i = 0; i < n; ++i) {
            if (visited.contains(i)) continue;

            pair<int, int> info{0, 0};
            dfs(dfs, i, info);

            if (info.first * (info.first - 1) == info.second) ++completedComponent;
        }

        return completedComponent;
    }
};