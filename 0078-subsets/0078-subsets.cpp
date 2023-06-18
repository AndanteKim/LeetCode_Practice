class Solution {
private:
    int n;
    void backtrack(int start, vector<int>& curr, vector<int>& nums, vector<vector<int>>& ans){
        if (start > n) return;
        ans.push_back(curr);
        for (int i = start; i < n; ++i){
            curr.push_back(nums[i]);
            backtrack(i + 1, curr, nums, ans);
            curr.pop_back();
        }
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int> curr;
        vector<vector<int>> ans;
        backtrack(0, curr, nums, ans);
        return ans;
    }
};