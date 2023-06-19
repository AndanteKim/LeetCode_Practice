class Solution {
private:
    void backtrack(int start, vector<int>& curr, vector<vector<int>>& graph, vector<vector<int>>& ans){
        if (start == graph.size() - 1){
            ans.push_back(curr);
            return;
        }
        
        for (int node : graph[start]){
            curr.push_back(node);
            backtrack(node, curr, graph, ans);
            curr.pop_back();
        }
    }
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> curr{{0}};
        backtrack(0, curr, graph, ans);
        
        return ans;
    }
};