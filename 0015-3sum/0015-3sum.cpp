class Solution {
private:
    int n;
    void twoSum(vector<int>& nums, int i, vector<vector<int>>& ans){
        int j = i + 1;
        unordered_set<int> seen;
        
        while (j < n){
            int complement = -(nums[i] + nums[j]);
            
            if (seen.find(complement) != seen.end()){
                ans.push_back({nums[i], nums[j], complement});
                while (j + 1 < n && nums[j] == nums[j + 1]) ++j;
            }
            seen.insert(nums[j]);
            ++j;
        }
    }
    
    
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; ++i){
            if (nums[i] > 0) break;
            if (i == 0 || nums[i - 1] != nums[i])
                twoSum(nums, i, ans);
        }
        
        return ans;
    }
};