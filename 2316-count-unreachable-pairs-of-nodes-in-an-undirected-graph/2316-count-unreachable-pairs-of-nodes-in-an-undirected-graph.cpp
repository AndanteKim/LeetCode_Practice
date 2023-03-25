#define ll long long

class Solution {
    int bfs(int node, vector<vector<int>>& adj, vector<bool>& visited){
        int count = 1;
        queue<int> *q = new queue<int>;
        visited[node] = true;
        q -> push(node);
        
        while (!q -> empty()){
            int curr_node = q -> front();
            q -> pop();
            
            for (int neighbor : adj[curr_node]){
                if (!visited[neighbor]){
                    visited[neighbor] = true;
                    ++count;
                    q -> push(neighbor);
                }
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
        
        vector<bool> visited(n);
        ll numberOfPairs = 0, sizeOfComponent = 0, remainingNodes = n;
        
        for (int node = 0; node < n; ++node){
            if (!visited[node]){
                sizeOfComponent = bfs(node, adj, visited);
                numberOfPairs += sizeOfComponent * (remainingNodes - sizeOfComponent);
                remainingNodes -= sizeOfComponent;
            }
        }
        
        return numberOfPairs;
    }
};