class Solution {
private:
    void backtrack(int start, vector<int>& nums, vector<vector<int>>& ans){
        if (start == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        unordered_set<int> lookup;
        
        for (int i = start; i < nums.size(); ++i){
            if (lookup.find(nums[i]) == lookup.end()){
                swap(nums[start], nums[i]);
                backtrack(start + 1, nums, ans);
                swap(nums[start], nums[i]);
                lookup.insert(nums[i]);
            }
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(0, nums, ans);
        return ans;
    }
};