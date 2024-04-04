class Solution {
private:
    int n;
    void twoSum(vector<int>& nums, int i, vector<vector<int>>& ans){
        int j = i + 1;
        unordered_set<int> seen;
        
        for (int j = i + 1; j < n; ++j){
            int complement = -(nums[i] + nums[j]);
            if (seen.count(complement)){
                ans.push_back({nums[i], complement, nums[j]});
                while (j + 1 < n && nums[j] == nums[j + 1]) ++j;
            }
            seen.insert(nums[j]);
        }
    }
    
    
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n && nums[i] <= 0; ++i){
            if (i == 0 || nums[i - 1] != nums[i])
                twoSum(nums, i, ans);
        }
        
        return ans;
    }
};