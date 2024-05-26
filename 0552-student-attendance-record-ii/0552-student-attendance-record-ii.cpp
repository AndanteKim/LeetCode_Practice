class Solution {
private:
    int mod = 1'000'000'007, n;
    int dp(vector<vector<vector<int>>>& memo, int day, int absent, int late){
        // base case
        if (day == n){
            return (absent < 2 && late < 3)? 1:0;
        }
        
        // If a student violates one of the criteria
        if (absent >= 2 || late >= 3) return 0;
        
        // Call cache which we already calculated
        if (memo[day][absent][late] != -1) return memo[day][absent][late];
        
        // If the student is present
        int ways = dp(memo, day + 1, absent, 0) % mod;
        
        // If the student is late
        ways = (ways + dp(memo, day + 1, absent, late + 1)) % mod;
        
        // If the student is absent
        ways = (ways + dp(memo, day + 1, absent + 1, 0)) % mod;
        
        return memo[day][absent][late] = ways % mod;
    }
    
public:
    int checkRecord(int n) {
        this -> n = n;
        vector memo(n + 1, vector<vector<int>>(4, vector<int>(3, -1)));
        return dp(memo, 0, 0, 0);
    }
};