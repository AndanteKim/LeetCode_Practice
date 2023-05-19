class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);
        
        for (int node = 0; node < n; ++node){
            if (colors[node] != -1) continue;
            colors[node] = 0;
            queue<int> queue;
            queue.push(node);
            
            while(!queue.empty()){
                int curr = queue.front();
                queue.pop();
                
                for (int neighbor : graph[curr]){
                    if (colors[neighbor] == -1){
                        colors[neighbor] = colors[curr] ^ 1;
                        queue.push(neighbor);
                    }
                    else if (colors[neighbor] == colors[curr]) return false;
                }
            }
        }
        
        return true;
    }
};