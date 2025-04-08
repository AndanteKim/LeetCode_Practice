class Solution {
private:
    void dfs(int node, vector<bool>& visited, vector<vector<int>>& graph){
        if (visited[node]) return;

        visited[node] = true;
        for (int neighbor : graph[node]){
            dfs(neighbor, visited, graph);
        }
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<vector<int>> graph(n);
        int ans = 0;
        for (vector<int>& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        for (int node = 0; node < n; ++node){
            if (visited[node]) continue;
            ++ans;
            dfs(node, visited, graph);
        }

        return ans;
    }
};