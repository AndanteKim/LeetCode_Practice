class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> dp(nums.size());
        
        for (int i = 0; i < nums.size(); ++i){
            if (!dq.empty() && i - dq.front() > k) dq.pop_front();
            dp[i] = (!dq.empty()? dp[dq.front()] : 0) + nums[i];
            while (!dq.empty() && dp[dq.back()] < dp[i])
                dq.pop_back();
            
            if (dp[i] > 0)
                dq.push_back(i);
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};