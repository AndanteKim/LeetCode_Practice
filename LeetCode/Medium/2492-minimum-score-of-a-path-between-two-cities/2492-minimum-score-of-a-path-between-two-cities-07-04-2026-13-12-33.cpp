class Solution {
private:
    int ans = std::numeric_limits<int>::max();

    void dfs(int node, vector<bool>& visited, vector<vector<pair<int, int>>>& graph) {
        for (const auto& [neighbor, cost] : graph[node]) {
            ans = min(ans, cost);
            if (visited[neighbor]) continue;
            visited[neighbor] = true;
            dfs(neighbor, visited, graph);
        }
    }

public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n + 1);
        
        for (const auto& road : roads) {
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }

        vector<bool> visited(n + 1, false);
        visited[1] = true;
        dfs(1, visited, graph);

        return ans;
    }
};