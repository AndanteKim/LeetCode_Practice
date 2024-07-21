class Solution {
private:
    // Find the topologically sorted sequence using Kahn's algorithm
    vector<int> topoSort(vector<vector<int>>& edges, int n){
        // Create an adjacency list to store the edges.
        vector<vector<int>> adj(n + 1);
        vector<int> deg(n + 1);
        
        for (vector<int>& e : edges){
            adj[e[0]].push_back(e[1]);
            ++deg[e[1]];
        }
        
        queue<int> q;
        
        // Push all integers with in-degree 0 in the queue.
        for (int i = 1; i <= n; ++i)
            if (deg[i] == 0)
                q.push(i);
        
        vector<int> order;
        while (!q.empty()){
            int f = q.front(); q.pop();
            order.push_back(f);
            --n;
            
            for (int v : adj[f]){
                --deg[v];
                
                if (deg[v] == 0)
                    q.push(v);
            }
        }
        
        // If we have not visited all integers, return empty array.
        return (n != 0)? vector<int>{} : order;
    }
    
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // Store the topologically sorted sequences
        vector<int> orderRows = topoSort(rowConditions, k);
        vector<int> orderCols = topoSort(colConditions, k);
        
        // If no topological sort exists, return empty array
        if (orderRows.empty() || orderCols.empty())
            return vector<vector<int>>{};
        
        vector matrix(k, vector<int>(k));
        for (int i = 0; i < k; ++i){
            for (int j = 0; j < k; ++j)
                if (orderRows[i] == orderCols[j])
                    matrix[i][j] = orderRows[i];
        }
        
        return matrix;
    }
};