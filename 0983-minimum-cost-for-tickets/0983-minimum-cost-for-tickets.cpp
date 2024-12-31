class Solution {
private:
    unordered_set<int> isTravelNeeded;

    int solve(vector<int>& days, vector<int>& costs, vector<int>& dp, int currDay){
        // Base case: If we've iterated over travel days, return 0.
        if (currDay > days.back())
            return 0;

        // If already calculated, return from here with the stored answer.
        if (dp[currDay] != -1)
            return dp[currDay];

        // If we don't need to travel on this day, move on to next day.
        if (!isTravelNeeded.count(currDay))
            return solve(days, costs, dp, currDay + 1);
        
        int oneDay = costs[0] + solve(days, costs, dp, currDay + 1);
        int sevenDays = costs[1] + solve(days, costs, dp, currDay + 7);
        int thirtyDays = costs[2] + solve(days, costs, dp, currDay + 30);

        // Store the cost with the minimum of the three options.
        return dp[currDay] = min(oneDay, min(sevenDays, thirtyDays));
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // The last day on which we need to travel.
        int lastDay = days.back();
        vector<int> dp(lastDay + 1, -1);

        // Mark the days on which we need to travel.
        for (int day : days)
            isTravelNeeded.insert(day);

        return solve(days, costs, dp, 1);
    }
};