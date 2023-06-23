class Solution {
private:
    void backtrack(int remain, vector<int>& curr, int start, vector<int>& candidates, vector<vector<int>>& ans){
        if (remain == 0){
            ans.push_back(curr);
            return;
        }
        
        unordered_set<int> seen;
        for (int i = start; i < candidates.size(); ++i){
            if (seen.find(candidates[i]) == seen.end() && candidates[i] <= remain){
                curr.push_back(candidates[i]);
                backtrack(remain - candidates[i], curr, i + 1, candidates, ans);
                curr.pop_back();
                seen.insert(candidates[i]);
            }
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        backtrack(target, curr, 0, candidates, ans);
        
        return ans;
    }
};