class Solution {
private:
    int dfs(int node, vector<int>& memo, unordered_map<int, vector<int>>& graph, vector<int>& time){
        if (memo[node] != -1)
            return memo[node];
        
        if (graph[node].size() == 0)
            return time[node];
        
        int ans = 0;
        for (int neighbor : graph[node])
            ans = max(ans, dfs(neighbor, memo, graph, time));
        
        return memo[node] = time[node] + ans;
    }
    
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        // dfs + top down memoization dynamic programming
        vector memo(n, -1);
        unordered_map<int, vector<int>> graph;
        
        for (vector<int>& relation : relations){
            graph[relation[0] - 1].push_back(relation[1] - 1);
        }
        
        int ans = 0;
        for (int node = 0; node < n; ++node)
            ans = max(ans, dfs(node, memo, graph, time));
        
        return ans;
    }
};