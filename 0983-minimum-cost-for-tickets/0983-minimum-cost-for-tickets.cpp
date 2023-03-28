class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.back() + 1, 0);
        for (int i = 1; i < dp.size(); ++i){
            if (find(days.begin(), days.end(), i) != days.end()){
                dp[i] = min(min(dp[max(i-1, 0)] + costs[0], dp[max(i-7, 0)] + costs[1]),\
                            min(dp[max(i-7, 0)] + costs[1], dp[max(i-30, 0)] + costs[2]));
            }
            else dp[i] = dp[i-1];
        }
        
        return dp.back();
    }
};