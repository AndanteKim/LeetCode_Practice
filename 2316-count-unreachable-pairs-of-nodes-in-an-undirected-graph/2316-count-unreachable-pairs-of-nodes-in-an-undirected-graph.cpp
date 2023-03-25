#define ll long long

class Solution {
    int dfs(int node, vector<vector<int>>& adj, vector<bool>& visited){
        visited[node] = true;
        int count = 1;
        for (int neighbor : adj[node]){
            if (!visited[neighbor]){
                visited[neighbor] = true;
                count += dfs(neighbor, adj, visited);
            }
        }
        
        return count;
    }
    
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (vector<int>& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        ll numberOfPairs = 0, sizeOfComponent = 0, remainingNodes = n;
        vector<bool> visited(n);
        
        for(int node = 0; node < n; ++node){
            if (!visited[node]){
                sizeOfComponent = dfs(node, adj, visited);
                numberOfPairs += sizeOfComponent * (remainingNodes - sizeOfComponent);
                remainingNodes -= sizeOfComponent;
            }
        }
        
        return numberOfPairs;
    }
};