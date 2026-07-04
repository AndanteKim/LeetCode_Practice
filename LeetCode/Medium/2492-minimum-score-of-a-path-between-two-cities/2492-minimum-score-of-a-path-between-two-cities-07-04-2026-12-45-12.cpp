class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n + 1);

        for (const vector<int>& road : roads) {
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }

        queue<int> q;
        q.push(1);
        vector<bool> visited(n + 1);
        visited[1] = true;
        int ans = std::numeric_limits<int>::max();

        while (!q.empty()) {
            int node = q.front(); q.pop();

            for (auto& [neighbor, cost] : graph[node]) {
                ans = min(ans, cost);
                if (visited[neighbor]) continue;
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }

        return ans;
    }
};