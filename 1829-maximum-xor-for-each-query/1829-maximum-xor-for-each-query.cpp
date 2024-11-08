class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size(), xorProduct = 0;
        
        for (int num : nums)
            xorProduct ^= num;
        
        int mask = (1 << maximumBit) - 1;
        vector<int> ans(n);
        for (int i = 0; i < n; ++i){
            ans[i] = xorProduct ^ mask;
            
            // Remove the last element
            xorProduct ^= nums[n - 1 - i];
        }
        
        return ans;
    }
};