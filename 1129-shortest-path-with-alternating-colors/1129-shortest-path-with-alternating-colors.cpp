class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        constexpr int RED = 0, BLUE = 1;
        unordered_map<int, unordered_map<int, vector<int>>> graph;
        
        for (vector<int>& edge: redEdges){
            int x = edge[0], y = edge[1];
            graph[RED][x].push_back(y);
        }
        
        for (vector<int>& edge: blueEdges){
            int x = edge[0], y = edge[1];
            graph[BLUE][x].push_back(y);
        }
        
        vector<int> ans(n, INT_MAX);
        queue<vector<int>> queue;
        vector<vector<bool>> seen(n, vector<bool>(2, false));
        
        queue.push({0, RED, 0});
        queue.push({0, BLUE, 0});
        seen[0][RED] = true;
        seen[0][BLUE] = true;
        
        while(!queue.empty()){
            vector<int> curr = queue.front();
            queue.pop();
            
            int node = curr[0], color = curr[1], steps = curr[2];
            ans[node] = min(ans[node], steps);
            
            for (int neighbor : graph[color][node]){
                if (!seen[neighbor][1 - color]){
                    seen[neighbor][1 - color] = true;
                    queue.push({neighbor, 1 - color, steps + 1});
                }
            }
        }
        
        replace(ans.begin(), ans.end(), INT_MAX, -1);
        return ans;
    }
};