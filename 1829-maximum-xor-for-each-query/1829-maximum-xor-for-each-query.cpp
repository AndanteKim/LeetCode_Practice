class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> prefixXOR(n);
        prefixXOR[0] = nums[0];
        
        for (int i = 1; i < n; ++i)
            prefixXOR[i] = prefixXOR[i - 1] ^ nums[i];
        
        int mask = (1 << maximumBit) - 1;
        vector<int> ans(n);
        for (int i = 0; i < n; ++i){
            // Find k to maximize value
            int product = prefixXOR[n - 1 - i];
            ans[i] = product ^ mask;
        }
        
        return ans;
    }
};