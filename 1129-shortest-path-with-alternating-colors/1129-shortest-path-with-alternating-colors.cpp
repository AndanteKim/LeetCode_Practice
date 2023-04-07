class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> ans(n, -1);
        vector<vector<pair<int, int>>> adj(n);
        for (auto& redEdge : redEdges) adj[redEdge[0]].push_back({redEdge[1], 0});
        for (auto& blueEdge : blueEdges) adj[blueEdge[0]].push_back({blueEdge[1], 1});
        
        vector<vector<bool>> visited(n, vector<bool>(2, false));
        queue<vector<int>> *q = new queue<vector<int>>;
        q -> push({0, 0, -1});
        
        while (!q -> empty()){
            int node = q -> front()[0], distance = q -> front()[1], prevColor = q -> front()[2];
            q -> pop();
            ans[node] == -1? ans[node] = distance : ans[node] = min(ans[node], distance);
            
            for (auto& [neighbor, color] : adj[node]){
                if (color != prevColor && !visited[neighbor][color]){
                    visited[neighbor][color] = true;
                    q -> push({neighbor, distance + 1, color});
                }
            }
        }
        
        return ans;
    }
};