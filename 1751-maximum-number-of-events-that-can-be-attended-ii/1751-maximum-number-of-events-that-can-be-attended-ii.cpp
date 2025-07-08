class Solution {
private:
    int n;
    int dp(vector<vector<int>>& memo, vector<int>& starts, vector<vector<int>>& events, int currIndex, int count){
        // Base case
        if (currIndex == n || count == 0) return 0;
        if (memo[currIndex][count] != -1) return memo[currIndex][count];

        int nextIndex = upper_bound(starts.begin(), starts.end(), events[currIndex][1]) - starts.begin();

        return memo[currIndex][count] = max(dp(memo, starts, events, currIndex + 1, count), events[currIndex][2] + dp(memo, starts, events, nextIndex, count - 1));
    }

public:
    int maxValue(vector<vector<int>>& events, int k) {
        this -> n = events.size();
        vector<int> starts;
        sort(events.begin(), events.end());
        for (int i = 0; i < n; ++i) starts.push_back(events[i][0]);

        vector memo(n, vector<int>(k + 1, -1));
        return dp(memo, starts, events, 0, k);
    }
};