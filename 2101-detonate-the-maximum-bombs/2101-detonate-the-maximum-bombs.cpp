typedef long long ll;

class Solution {
    int dfs(int node, unordered_set<int>& visited, unordered_map<int, vector<int>>& graph){
        visited.insert(node);
        queue<int> queue{{node}};
        
        while (!queue.empty()){
            int curr = queue.front();
            queue.pop();
            
            for (int neighbor : graph[curr]){
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    queue.push(neighbor);
                }
            }
        }
        return visited.size();
    }
    
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        unordered_map<int, vector<int>> graph;
        int n = bombs.size(), ans = 0;
        
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                if (i == j) continue;
                int x_i = bombs[i][0], y_i = bombs[i][1], r_i = bombs[i][2];
                int x_j = bombs[j][0], y_j = bombs[j][1];
                if ((ll)(x_j - x_i) * (x_j - x_i) + (ll)(y_i - y_j) * (y_i - y_j) <= (ll)r_i * r_i) graph[i].push_back(j);
            }
        }
        
        for (int i = 0; i < n; ++i){
            unordered_set<int> visited;
            ans = max(ans, dfs(i, visited, graph));
        }
        
        return ans;
    }
};