class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> productFreq;

        for (int i = 0; i < n - 1; ++i){
            for (int j = i + 1; j < n; ++j)
                ++productFreq[nums[i] * nums[j]];
        }

        int ans = 0;
        for (const auto& [product, freq] : productFreq)
            ans += freq * (freq - 1) * 4;
        
        return ans;
    }
};