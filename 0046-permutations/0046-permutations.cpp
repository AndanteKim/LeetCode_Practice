class Solution {
private:
    int n;
    void backtrack(int start, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans){
        if (curr.size() == n){
            ans.push_back(curr);
            return;
        }
        
        for (int i = 0; i < n; ++i){
            if (find(curr.begin(), curr.end(), nums[i]) == curr.end()){
                curr.push_back(nums[i]);
                backtrack(i + 1, nums, curr, ans);
                curr.pop_back();
            }
        }
        
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        this -> n = nums.size();
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(0, nums, curr, ans);
        return ans;
    }
};