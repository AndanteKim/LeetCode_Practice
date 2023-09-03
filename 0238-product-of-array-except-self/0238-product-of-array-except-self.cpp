class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n), L(n), R(n);
        L[0] = 1, R[n - 1] = 1;
        
        for (int i = 1; i < n; ++i) L[i] = L[i - 1] * nums[i - 1];
        for (int i = n - 2; i >= 0; --i) R[i] = R[i + 1] * nums[i + 1];
        
        for (int i = 0; i < n; ++i) ans[i] = L[i] * R[i];
        return ans;
    }
};