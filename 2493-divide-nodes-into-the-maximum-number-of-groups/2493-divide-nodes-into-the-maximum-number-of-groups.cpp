class Solution {
private:
    int n;

    // Find the root of the given node in the Union-Find structure
    int find(int node, vector<int>& parent){
        while (parent[node] != -1) node = parent[node];
        
        return node;
    }

    // Union operation to merge two sets
    void unite(int node1, int node2, vector<int>& parent, vector<int>& depth){
        int root1 = find(node1, parent), root2 = find(node2, parent);

        // If both nodes already belong to the same set, no action needed
        if (root1 == root2) return;

        // If both nodes already belong to the same set, no action needed
        if (depth[root1] < depth[root2]) swap(root1, root2);
        
        // Union by rank (depth) to keep the tree balanced
        parent[root2] = root1;

        // If the depths are equal, increment the depth of the new root
        if (depth[root1] == depth[root2]) ++depth[root1];
        
    }

    // Function to calculate the number of groups for a given component starting from srcNode
    int getNumberOfGroups(int srcNode, vector<vector<int>>& graph){
        queue<int> q;
        q.push(srcNode);
        vector<int> layerSeen(n, -1);
        layerSeen[srcNode] = 0;
        int deepestLayer = 0;

        // Perform BFS to calculate the number of layers (groups)
        while (!q.empty()){
            int sz = q.size();

            for (int i = 0; i < sz; ++i){
                int currNode = q.front(); q.pop();
                for (int neighbor : graph[currNode]){
                    // If neighbor hasn't been visited, assign it to the next layer
                    if (layerSeen[neighbor] == -1){
                        layerSeen[neighbor] = deepestLayer + 1;
                        q.push(neighbor);
                    }
                    else{
                        // If the neighbor is already in the same layer, return -1
                        if (layerSeen[neighbor] == deepestLayer)
                            return -1;
                    }
                }
            }
            ++deepestLayer;
        }

        return deepestLayer;
    }

public:
    // Main function to calculate the maximum number of groups for the entire graph
    int magnificentSets(int n, vector<vector<int>>& edges) {
        this -> n = n;
        vector graph(n, vector<int>());
        vector<int> parent(n, -1), depth(n);

        // Build the adjacency list and apply Union-Find for each edge
        for (const vector<int>& edge : edges){
            graph[edge[0] - 1].push_back(edge[1] - 1);
            graph[edge[1] - 1].push_back(edge[0] - 1);
            unite(edge[0] - 1, edge[1] - 1, parent, depth);
        }
        
        unordered_map<int, int> numberOfGroupsForComponent;

        // For each node, calculate the maximum number of groups for its component
        for (int node = 0; node < n; ++node){
            int numberOfGroups = getNumberOfGroups(node, graph);
            if (numberOfGroups == -1) return -1;    // If invalid split, return -1

            int rootNode = find(node, parent);
            numberOfGroupsForComponent[rootNode] = max(numberOfGroupsForComponent[rootNode], numberOfGroups);
        }
        
        // Calculate the total number of groups across all components
        int maxNumberOfGroups = 0;

        for (const auto& [node, numberOfGroups] : numberOfGroupsForComponent)
            maxNumberOfGroups += numberOfGroups;
        
        return maxNumberOfGroups;
    }
};