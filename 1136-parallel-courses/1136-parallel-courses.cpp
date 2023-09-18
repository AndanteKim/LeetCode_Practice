class Solution {
private:
    int dfs(int node, vector<int>& visited, vector<vector<int>>& graph){
        if (visited[node])
            return visited[node];
        else
            // mark as visiting
            visited[node] = -1;
        
        int maxLength = 1;
        for (int endNode : graph[node]){
            int length = dfs(endNode, visited, graph);
            // we meet a cycle
            if (length == -1)
                return -1;
            maxLength = max(length + 1, maxLength);
        }
        // mark as visited
        return visited[node] = maxLength;
    }
    
    
    
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> graph(n + 1);
        vector<int> visited(n + 1);
        
        for (vector<int>& relation : relations) graph[relation[0]].push_back(relation[1]);
        
        int maxLength = -1;
        for (int node = 1; node <= n; ++node){
            int length = dfs(node, visited, graph);
            if (length == -1) return -1;
            maxLength = max(length, maxLength);
        }
        
        return maxLength;
    }
};