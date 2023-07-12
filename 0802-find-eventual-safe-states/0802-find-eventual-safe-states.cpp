class Solution {
private:
    bool dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& inStack){
        if (inStack[node]) return true;
        if (visited[node]) return false;
        
        inStack[node] = true;
        visited[node] = true;
        for (int neighbor : graph[node]){
            if (dfs(neighbor, graph, visited, inStack)) return true;
        }
        inStack[node] = false;
        return false;
    }
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> inStack(n, false), visited(n, false);
        for (int i = 0; i < n; ++i) dfs(i, graph, visited, inStack);
        vector<int> ans;
        for (int i = 0; i < n; ++i) if (!inStack[i]) ans.push_back(i);
        
        return ans;
    }
};