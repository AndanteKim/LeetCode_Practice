class Solution {
private:
    bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& inStack){
        if (inStack[node]) return true;
        if (visited[node]) return false;
        
        visited[node] = true, inStack[node] = true;
        for (int neighbor : adj[node]){
            if (dfs(neighbor, adj, visited, inStack)) return true;
        }
        inStack[node] = false;
        return false;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, false), inStack(numCourses, false);
        vector<vector<int>> adj(numCourses);
        
        for (vector<int>& prerequisite : prerequisites){
            adj[prerequisite[1]].push_back(prerequisite[0]);
        }
        
        for (int i = 0; i < numCourses; ++i){
            if (dfs(i, adj, visited, inStack)) return false;
        }
        
        return true;
    }
};