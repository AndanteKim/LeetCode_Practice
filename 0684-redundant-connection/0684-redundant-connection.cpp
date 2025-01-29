class Solution {
private:
    int n;
    
    // Performs DFS and returns True if there's a path between src and target
    bool isConnected(int src, int target, vector<bool>& visited, vector<vector<int>>& adjList){
        visited[src] = true;

        if (src == target)
            return true;

        bool isFound = false;

        for (int adj : adjList[src]){
            if (!visited[adj])
                isFound |= isConnected(adj, target, visited, adjList);
            
        }

        return isFound;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        this -> n = edges.size();
        vector<vector<int>> adjList(n);
        
        for (const vector<int>& edge : edges){
            vector<bool> visited(n, false);
            
            // If DFS returns True, we'll return the edge.
            if (isConnected(edge[0] - 1, edge[1] - 1, visited, adjList))
                return edge;

            adjList[edge[0] - 1].push_back(edge[1] - 1);
            adjList[edge[1] - 1].push_back(edge[0] - 1);
        }

        return vector<int>{};
    }
};