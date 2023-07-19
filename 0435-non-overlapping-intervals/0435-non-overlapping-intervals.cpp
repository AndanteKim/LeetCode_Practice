class Solution {
private:
    int n;
    int f(int i, vector<vector<int>>& intervals, vector<int>& dp){
        if (i == this -> n) return 0;
        if (dp[i] != -1) return dp[i];
        
        int notTake = 0 + f(i + 1, intervals, dp);
        
        int currStart = intervals[i][0], currEnd = intervals[i][1];
        int idx = lower_bound(intervals.begin() + i + 1, intervals.end(), vector<int>{currEnd, currEnd}) - intervals.begin();
        int take = 1 + f(idx, intervals, dp);
        
        return dp[i] = max(take, notTake);
    }
    
    
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        this -> n = intervals.size();
        sort(intervals.begin(), intervals.end());
        
        vector<int> dp(n, -1);
        return this -> n - f(0, intervals, dp);
    }
};