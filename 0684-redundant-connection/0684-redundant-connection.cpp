class Solution {
private:
    int n, startCycle = -1;

    // Perform the DFS and store a node in the cycle as cycleStart
    void dfs(int src, vector<bool>& visited, vector<int>& parent, vector<vector<int>>& graph){
        visited[src] = true;

        for (int adj : graph[src]){
            if (!visited[adj]){
                parent[adj] = src;
                dfs(adj, visited, parent, graph);
            }

            // If the node is visited and the parent is different then
            // the node is part of the cycle
            else if (parent[src] != adj && startCycle == -1){
                parent[adj] = src;
                startCycle = adj;
            }
        }

    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        this -> n = edges.size();
        vector graph(n, vector<int>{});
        
        for (const vector<int>& edge : edges){
            int u = edge[0], v = edge[1];
            graph[u - 1].push_back(v - 1);
            graph[v - 1].push_back(u - 1);
        }

        vector<bool> visited(n, false);
        vector<int> parent(n, -1);
        dfs(0, visited, parent, graph);
        
        unordered_set<int> isConnected;
        int node = startCycle;

        // Start from the startCycle node and backtrack to get all the nodes
        // in the cycle. Mark them all in the map.
        do {
            node = parent[node];
            isConnected.insert(node);
        } while(node != startCycle);

        // If both nodes of the edge were marked as cycle nodes then this edge
        // can be removed.
        for (int i = n - 1; i >= 0; --i){
            if (isConnected.count(edges[i][0] - 1) && isConnected.count(edges[i][1] - 1))
                return edges[i];
        }

        return vector<int>{};
    }
};