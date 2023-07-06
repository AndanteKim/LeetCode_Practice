class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), ans = INT_MAX;
        vector<int> prefixSum(n + 1);
        for (int i = 0; i < n; ++i) prefixSum[i + 1] = prefixSum[i] + nums[i];
        
        for (int i = n; i >= 0 && prefixSum[i] >= target; --i){
            int left = 0, right = n;
            
            while (left < right){
                int mid = left + ((right - left) >> 1);
                if (prefixSum[i] - prefixSum[mid] >= target) left = mid + 1;
                else right = mid;
            }
            ans = min(ans, i - left + 1);
        }
        
        return ans == INT_MAX? 0 : ans;
    }
};