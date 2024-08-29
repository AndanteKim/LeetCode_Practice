class Solution {
private:
    int n;
    
    // DFS to visit all stones in a connected component
    void dfs(int stone, vector<bool>& visited, vector<vector<int>>& adj){
        visited[stone] = true;
        
        for (int neighbor : adj[stone]){
            if (!visited[neighbor])
                dfs(neighbor, visited, adj);
        }
    }
    
public:
    int removeStones(vector<vector<int>>& stones) {
        this -> n = stones.size();
        int numOfConnectedComponents = 0;
        
        // Adjacent list to store graph connections
        vector<vector<int>> adj(n);
        
        // Build the graph: Connect stones sharing the same row or column
        for (int i = 0; i < n; ++i){
            for (int j = i + 1; j < n; ++j){
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        // Traverse all stones using DFS to count connected components
        vector<bool> visited(n);
        for (int i = 0; i < n; ++i){
            if (!visited[i]){
                dfs(i, visited, adj);
                ++numOfConnectedComponents;
            }
        }
        
        // Maximum stones that can be removed is total stones - number of connected components
        return n - numOfConnectedComponents;
    }
};