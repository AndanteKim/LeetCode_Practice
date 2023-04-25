class Solution {
    bool dfs(int node, int start, vector<int>& color, vector<vector<int>>& adj){
        color[node] = start;
        for (int neighbor : adj[node]){
            if (color[neighbor] == color[node]) return false;
            if (color[neighbor] == -1){
                if (!dfs(neighbor, 1 - start, color, adj)) return false;
            }
        }
        return true;
    }
    
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector adj(n + 1, vector<int>());
        vector color(n + 1, -1);
        
        for (auto& dislike : dislikes){
            adj[dislike[0]].push_back(dislike[1]);
            adj[dislike[1]].push_back(dislike[0]);
        }
        
        for (int i = 1; i <= n; ++i){
            if (color[i] == -1){
                if (!dfs(i, 0, color, adj)) return false;
            }
        }
        
        return true;
    }
};