class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        unordered_map<int, vector<int>> connected;
        int n = bombs.size();
        
        // Connect the graph
        for (int i = 0; i < n - 1; ++i){
            int x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
            
            for (int j = i + 1; j < n; ++j){
                int x2 = bombs[j][0], y2 = bombs[j][1], r2 = bombs[j][2];
                
                double influence = (double)pow(((long)abs(x1 - x2) * abs(x1 - x2) + (long)abs(y1 - y2) * abs(y1 - y2)), 0.5);
                if (influence <= r1)
                    connected[i].push_back(j);
                
                if (influence <= r2)
                    connected[j].push_back(i);
            }
        }
        
        // Test how many chained bombs are exploded
        int ans = 0;
        for (int i = 0; i < n; ++i){
            queue<int> queue;
            queue.push(i);
            vector<bool> visited(n, false);
            visited[i] = true;
            int exploded = 0;
            while (!queue.empty()){
                int node = queue.front(); queue.pop();
                ++exploded;
                
                for (int neighbor : connected[node]){
                    if (!visited[neighbor]){
                        visited[neighbor] = true;
                        queue.push(neighbor);
                    }
                }
            }
            
            ans = max(ans, exploded);
        }
        
        return ans;
    }
};