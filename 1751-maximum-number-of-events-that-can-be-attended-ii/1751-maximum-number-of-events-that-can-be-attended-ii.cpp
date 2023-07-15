class Solution {
private:
    int n;
    int dfs(int currIndex, int count, vector<int>& starts, vector<vector<int>>& events, vector<vector<int>>& dp){
        if (currIndex == this -> n || count == 0) return 0;
        if (dp[count][currIndex] != -1) return dp[count][currIndex];
        
        int nextIndex = upper_bound(starts.begin(), starts.end(), events[currIndex][1]) - starts.begin();
        dp[count][currIndex] = max(dfs(currIndex + 1, count, starts, events, dp), events[currIndex][2] + dfs(nextIndex, count - 1, starts, events, dp));
        return dp[count][currIndex];
    }
    
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        this -> n = events.size();
        vector<int> starts(this -> n);
        for (int i = 0; i < n; ++i) starts[i] = events[i][0];
        vector<vector<int>> dp(k + 1, vector<int>(n, -1));
        
        return dfs(0, k, starts, events, dp);
    }
};