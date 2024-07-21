class Solution {
private:
    vector<int> topoSort(vector<vector<int>>& edges, int n){
        unordered_map<int, vector<int>> adj;
        
        // Build adjacency list
        for (vector<int>& e: edges){
            int x = e[0], y = e[1];
            adj[x].push_back(y);
        }
        
        // 0: not visited, 1: visiting, 2: visited
        vector<int> visited(n + 1);
        vector<int> order;
        bool hasCycle = false;
        
        // Perform DFS for each node
        for (int node = 1; node <= n; ++node){
            if (!visited[node]){
                dfs(node, adj, visited, order, hasCycle);
                
                // Return empty if cycle detected
                if (hasCycle)
                    return vector<int>{};
            }
        }
        
        // Reverse to get the correct order
        reverse(order.begin(), order.end());
        return order;
    }
    
    void dfs(int node, unordered_map<int, vector<int>>& adj, vector<int>& visited, vector<int>& order, \
            bool& hasCycle){
        // Mark node as visiting
        visited[node] = 1;
        
        for (int neighbor : adj[node]){
            if (!visited[neighbor]){
                dfs(neighbor, adj, visited, order, hasCycle);
                
                // Early exit if a cycle is detected
                if (hasCycle)
                    return;
            }
            else if (visited[neighbor] == 1){
                // Cycle detected
                hasCycle = true;
                return;
            }
        }
        
        // Mark node as visited
        visited[node] = 2;
        
        // Add node to the order
        order.push_back(node);
    }
    
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // Store the topologically sorted sequences.
        vector<int> orderRows = topoSort(rowConditions, k);
        vector<int> orderCols = topoSort(colConditions, k);
        
        // If no topological sort exists, return empty array.
        if (orderRows.empty() || orderCols.empty()) return vector<vector<int>> {};
        
        unordered_map<int, int> numRows, numCols;
        for (int i = 0; i < orderRows.size(); ++i)
            numRows[orderRows[i]] = i;
        
        for (int i = 0; i < orderCols.size(); ++i)
            numCols[orderCols[i]] = i;
        
        vector matrix(k, vector<int>(k));
        for (int num = 1; num <= k; ++num){
            if (numRows.count(num) && numCols.count(num)){
                matrix[numRows[num]][numCols[num]] = num;
            }
        }
        
        return matrix;
    }
};