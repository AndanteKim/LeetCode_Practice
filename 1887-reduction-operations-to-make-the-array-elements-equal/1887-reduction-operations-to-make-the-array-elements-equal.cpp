class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0, up = 0;
        for (int i = 1; i < nums.size(); ++i){
            if (nums[i - 1] != nums[i])
                ++up;
            ans += up;
        }
        
        return ans;
    }
};