class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> graph;
        
        for (auto& edge : edges){
            int start = edge[0], end = edge[1];
            
            ++graph[start];
            ++graph[end];
        }
        
        int ans = -1, mx = -1;
        for (auto& [key, freq] : graph){
            if (mx < freq){
                mx = freq;
                ans = key;
            }
        }
        
        return ans;
    }
};