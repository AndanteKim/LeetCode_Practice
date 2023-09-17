class Solution {
private:
    int dp(int node, int mask, vector<vector<int>>& cache, vector<vector<int>>& graph){
        if (cache[node][mask] != 0)
            return cache[node][mask];
        
        if ((mask & (mask - 1)) == 0)
            // base case: mask only has a single "1", meaning that only one node has
            // been visited the current node
            return 0;
        
        // avoid infinite loop in recursion
        cache[node][mask] = INT_MAX - 1;
        
        for (int neighbor : graph[node]){
            if ((mask & (1 << neighbor)) != 0){
                int alreadyVisited = dp(neighbor, mask, cache, graph);
                int notVisited = dp(neighbor, mask ^ (1 << node), cache, graph);
                int betterOption = min(alreadyVisited, notVisited);
                cache[node][mask] = min(cache[node][mask], 1 + betterOption);
            }
        }
        return cache[node][mask];
    }
    
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size(), endingMask = (1 << n) - 1;
        vector<vector<int>> cache(n + 1, vector<int>(endingMask + 1));
        
        int ans = INT_MAX;
        for (int node = 0; node < n; ++node)
            ans = min(ans, dp(node, endingMask, cache, graph));
            
        return ans;
    }
};