class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        if (graph.size() == 1) return 0;
        
        int n = graph.size(), endingMask = (1 << n) - 1, steps = 0;
        vector<vector<bool>> seen(n, vector<bool>(endingMask));
        vector<pair<int, int>> queue;
        
        for (int i = 0; i < n; ++i){
            queue.push_back(make_pair(i, 1 << i));
            seen[i][1 << i] = true;
        }
        
        while (!queue.empty()){
            vector<pair<int, int>> nextQueue;
            
            for (int i = 0; i < queue.size(); ++i){
                auto[node, mask] = queue[i];
                
                for (int neighbor : graph[node]){
                    int nextMask = mask | (1 << neighbor);
                    if (nextMask == endingMask) return 1 + steps;
                    
                    if (!seen[neighbor][nextMask]){
                        seen[neighbor][nextMask] = true;
                        nextQueue.push_back(make_pair(neighbor, nextMask));
                    }
                }
            }
            
            ++steps;
            queue = nextQueue;
        }
        
        return -1;
    }
};