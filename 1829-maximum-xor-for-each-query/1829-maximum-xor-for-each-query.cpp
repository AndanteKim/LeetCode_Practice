class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size(), startNum = 0;
        int maxNum = (1 << maximumBit) - 1;
        vector<int> ans(n);
        
        for (int i = 0; i < n; ++i){
            startNum ^= nums[i];
            ans[i] = maxNum ^ startNum;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};