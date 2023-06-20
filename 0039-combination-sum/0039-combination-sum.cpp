class Solution {
private:
    int n, target;
    void backtrack(vector<int>& path, int curr, int start, vector<int>& candidates, vector<vector<int>>& ans){
        if (curr == target){
            ans.push_back(path);
            return;
        }
        
        for (int i = start; i < n; ++i){
            if (curr + candidates[i] <= target){
                path.push_back(candidates[i]);
                backtrack(path, curr + candidates[i], i, candidates, ans);
                path.pop_back();
            }
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        this -> target = target;
        vector<vector<int>> ans;
        vector<int> path;
        backtrack(path, 0, 0, candidates, ans);
        
        return ans;
    }
};