class Solution {
private:
    int n;
    void twoSumII(vector<int>& nums, int i, vector<vector<int>>& ans){
        int lo = i + 1, hi = n - 1, sum;
        
        while (lo < hi){
            sum = nums[lo] + nums[hi] + nums[i];
            
            if (sum < 0)
                ++lo;
            else if (sum > 0)
                --hi;
            else{
                ans.push_back({nums[i], nums[lo], nums[hi]});
                ++lo;
                --hi;
                while (lo < hi && nums[lo - 1] == nums[lo]) ++lo;
            }
        }
    }
    
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; ++i){
            if (nums[i] > 0)
                break;
            if (i == 0 || nums[i - 1] != nums[i])
                twoSumII(nums, i, ans);
        }
        
        return ans;
    }
};