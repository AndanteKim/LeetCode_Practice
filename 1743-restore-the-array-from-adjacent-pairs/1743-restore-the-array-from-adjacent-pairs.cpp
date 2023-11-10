class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> graph;
        
        for (vector<int>& edges : adjacentPairs){
            int x = edges[0], y = edges[1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        
        int curr;
        for (auto& [num, route] : graph){
            if (route.size() == 1){
                curr = num;
                break;
            }
        }
        
        vector<int> ans{curr};
        int prev = INT_MAX;
        
        while (ans.size() < graph.size()){
            for (int neighbor : graph[curr]){
                if (neighbor != prev){
                    ans.push_back(neighbor);
                    prev = curr;
                    curr = neighbor;
                    break;
                }
            }
        }
        
        return ans;
    }
};