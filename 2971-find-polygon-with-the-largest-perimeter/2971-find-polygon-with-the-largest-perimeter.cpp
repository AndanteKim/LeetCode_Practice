typedef long long ll;

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return -1;
        
        sort(nums.begin(), nums.end());
        vector<ll> prefixSum(n + 1);
        
        for (int i = 1; i <= n; ++i)
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        
        for (int i = n - 1; i >= 1; --i){
            if (nums[i] < prefixSum[i])
                return prefixSum[i] + nums[i];
        }
        
        return -1;
    }
};