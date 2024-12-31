class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // Bottom-up Dynamic Programming
        int lastDay = days.back(), i = 0;
        vector<int> dp(lastDay + 1);

        for (int day = 1; day <= lastDay; ++day){
            if (day < days[i])
                dp[day] = dp[day - 1];
            else{
                ++i;
                dp[day] = min({
                    dp[day - 1] + costs[0],\
                    dp[max(0, day - 7)] + costs[1],\
                    dp[max(0, day - 30)] + costs[2]
                });
            }
        }

        return dp[lastDay];
    }
};