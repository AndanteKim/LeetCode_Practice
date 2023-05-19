class Solution {
    bool dfs(int node, vector<int>& colors, int color, vector<vector<int>>& graph){
        if (colors[node] != -1){
            if (colors[node] != color) return false;
            return true;
        }
        colors[node] = color;
        for (int neighbor : graph[node]){
            if (dfs(neighbor, colors, color ^ 1, graph) == false) return false;
        }
        return true;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);
        for (int node = 0; node < n; ++node){
            if (colors[node] == -1) {
                if (dfs(node, colors, 0, graph) == false) return false;
            }
        }
        return true;
    }
};