class Solution {
private:
    int m;
    
    void dfs(int start, vector<bool>& visited, vector<vector<int>>& graph){
        if (visited[start])
            return;
        
        visited[start] = true;
        for (int neighbor : graph[start]){
            dfs(neighbor, visited, graph);
        }
    }
    
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        this -> m = edges.size();
        
        for (const auto& edge : edges)
            graph[edge[0]].push_back(edge[1]);
        
        for (int node = 0; node < n; ++node){
            vector<bool> visited(n);
            dfs(node, visited, graph);
            
            if (accumulate(visited.begin(), visited.end(), 0) == n)
                return node;
        }
        
        return -1;
    }
};