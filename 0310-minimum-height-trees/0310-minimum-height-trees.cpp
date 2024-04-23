class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // edge cases
        vector<int> leaves;
        if (n <= 2){
            for (int i = 0; i < n; ++i) leaves.push_back(i);
            return leaves;
        }
        
        // Build the graph with the adjacency list
        vector<unordered_set<int>> neighbors(n);
        for (vector<int>& edge : edges){
            neighbors[edge[0]].insert(edge[1]);
            neighbors[edge[1]].insert(edge[0]);
        }
        
        // Initialize the first layeer of leaves
        for (int i = 0; i < n; ++i){
            if (neighbors[i].size() == 1) leaves.push_back(i);
        }
        
        // Trim the leaves until reaching the centroids
        int remainingNodes = n;
        while (remainingNodes > 2){
            remainingNodes -= leaves.size();
            vector<int> newLeaves;
            
            // remove the current leaves along with the edges
            while (!leaves.empty()){
                int leaf = leaves.back(); leaves.pop_back();
                
                // The only neighbor left for the leaf node
                int neighbor = *neighbors[leaf].begin();
                // Remove the only edge left
                neighbors[neighbor].erase(leaf);
                if (neighbors[neighbor].size() == 1)
                    newLeaves.push_back(neighbor);
            }
            
            // Prepare for the next round
            leaves = newLeaves;
        }
        
        // The remaining nodes are the centroids of the graph
        return leaves;
    }
};