class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size(), hottest = 0;
        vector<int> ans(n, 0);
        for (int curr_day = n - 1; curr_day >= 0; --curr_day){
            int curr_temp = temperatures[curr_day];
            if (curr_temp >= hottest) {
                hottest = curr_temp;
                continue;
            }
            int days = 1;
            while (temperatures[curr_day + days] <= curr_temp){
                days += ans[curr_day + days];
            }
            ans[curr_day] = days;
        }
        return ans;
    }
};