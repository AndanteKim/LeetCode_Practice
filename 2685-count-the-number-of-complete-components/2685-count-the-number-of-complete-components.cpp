class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // Map to store frequency of each unique adjacency list
        map<vector<int>, int> componentCount;
        
        // Adjacency lists for each vertex
        vector<vector<int>> graph(n);

        // Initialize adjacency lists with self-loops
        for (int node = 0; node < n; ++node) graph[node].push_back(node);

        // Build adjacency lists from edges
        for (const vector<int>& edge : edges){
            int u = edge[0], v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // Count frequency of each unique adjacency pattern
        for (int node = 0; node < n; ++node){
            vector<int> neighbors = graph[node];
            sort(neighbors.begin(), neighbors.end());
            ++componentCount[neighbors];
        }

        // Count complete components where size equals frequency
        int ans = 0;
        for (const auto& [neighbors, freq] : componentCount)
            // Count commas to get original vector size
            if (static_cast<int>(neighbors.size()) == freq) ++ans;

        return ans;
    }
};