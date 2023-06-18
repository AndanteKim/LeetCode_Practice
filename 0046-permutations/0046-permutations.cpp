class Solution {
private:
    int n;
    void backtrack(int start, vector<int>& nums, vector<vector<int>>& ans){
        if (start == n){
            ans.push_back(nums);
            return;
        }
        
        for (int i = start; i < n; ++i){
            swap(nums[i], nums[start]);
            backtrack(start + 1, nums, ans);
            swap(nums[i], nums[start]);
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> ans;
        backtrack(0, nums, ans);
        return ans;
    }
};