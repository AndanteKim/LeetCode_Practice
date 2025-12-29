class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        long long T = accumulate(calories.begin(), calories.begin() + k, 0LL);
        int n = calories.size(), ans = T > upper? 1 : T < lower? -1 : 0, left = 0;

        for (int right = k; right < n; ++right) {
            T -= calories[left++];
            T += calories[right];
            ans += T > upper? 1 : T < lower? -1 : 0;
        }

        return ans;
    }
};