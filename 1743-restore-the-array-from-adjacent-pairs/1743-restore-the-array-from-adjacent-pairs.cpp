class Solution {
private:
    void dfs(int node, int prev, vector<int>& ans, unordered_map<int, vector<int>>& graph){
        ans.push_back(node);
        
        for (int neighbor : graph[node]){
            if (neighbor != prev){
                dfs(neighbor, node, ans, graph);
            }
        }
    }
    
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> graph;
        
        for (vector<int>& pairs : adjacentPairs){
            int x = pairs[0], y = pairs[1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        
        int root;
        for (auto& [node, route] : graph){
            if (route.size() == 1){
                root = node;
                break;
            }
        }
        
        vector<int> ans;
        dfs(root, NULL, ans, graph);
        return ans;
    }
};