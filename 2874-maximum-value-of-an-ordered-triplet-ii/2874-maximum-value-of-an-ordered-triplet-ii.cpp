class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMax(n), rightMax(n);

        for (int i = 1; i < n; ++i){
            leftMax[i] = max(leftMax[i - 1], nums[i - 1]);
            rightMax[n - 1 - i] = max(rightMax[n - i], nums[n - i]);
        }

        long long ans = 0;
        for (int j = 1; j < n - 1; ++j){
            ans = max(ans, (long long)(leftMax[j] - nums[j]) * rightMax[j]);
        }
        
        return ans;
    }
};