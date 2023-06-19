class Solution {
private:
    void backtrack(int prefix, vector<int>& curr, vector<int>& candidates, int target, vector<vector<int>>& ans){
        if (prefix >= target){
            if (prefix == target) ans.push_back(curr);
            return;
        }
        
        for (int i = 0; i < candidates.size(); ++i){
            if (curr.empty() || curr.back() <= candidates[i]){
                curr.push_back(candidates[i]);
                backtrack(prefix + candidates[i], curr, candidates, target, ans);
                curr.pop_back();
            }
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(0, curr, candidates, target, ans);
        return ans;
    }
};