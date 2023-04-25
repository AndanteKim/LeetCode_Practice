class Solution {
    bool bfs(int start, vector<int>& color, vector<vector<int>>& adj){
        queue<int> queue{{start}};
        color[start] = 0;
        
        while (!queue.empty()){
            int node = queue.front();
            queue.pop();
            for (int neighbor : adj[node]){
                if (color[neighbor] == color[node]) return false;
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    queue.push(neighbor);
                }
            }
        }
        return true;
    }
    
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector adj(n + 1, vector<int>());
        vector color(n+1, - 1);
        
        for (auto dislike : dislikes){
            adj[dislike[0]].push_back(dislike[1]);
            adj[dislike[1]].push_back(dislike[0]);
        }
        
        for (int i = 1; i <= n; ++i){
            if (color[i] == -1){
                if (!bfs(i, color, adj)) return false;
            }
        }
        
        return true;
    }
};