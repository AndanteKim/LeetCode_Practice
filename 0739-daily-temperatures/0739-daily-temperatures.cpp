class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size(), hottest = 0;
        vector<int> ans(n, 0);
        
        for (int currDay = n - 1; currDay >= 0; --currDay){
            int currTemperature = temperatures[currDay];
            if (currTemperature >= hottest){
                hottest = currTemperature;
                continue;
            }
            
            int days = 1;
            while (temperatures[currDay + days] <= currTemperature){
                // use the information from ans to search for the next warmer day
                days += ans[currDay + days];
            }
            ans[currDay] = days;
        }
        
        return ans;
    }
};