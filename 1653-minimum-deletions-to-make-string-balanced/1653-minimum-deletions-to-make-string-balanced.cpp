class Solution {
private:
    int n;
    int dp(int i, int prev, int length, string& s, vector<vector<int>>& memo){
        // Base case
        if (i == n)
            return 0;
        
        if (memo[i][s[prev] - 97] != -1)
            return memo[i][s[prev] - 97];
        
        int minDelete = INT_MAX;
        // If s[prev] = 'b' and s[i] = 'a' with prev < i.
        if (s[prev] > s[i])
            // Delete current character to find the equivalent or length with new start
            minDelete = min(1 + dp(i + 1, prev, length, s, memo), length + dp(i + 1, i, 0, s, memo));
        else
            // Delete current character to find the equivalent or just keep searching
            minDelete = min(dp(i + 1, i, length + 1, s, memo), 1 + dp(i + 1, prev, length, s, memo));
        
        return memo[i][s[prev] - 97] = minDelete;
    }
    
    
public:
    int minimumDeletions(string s) {
        this -> n = s.size();
        vector memo(n + 1, vector<int>(2, -1));
        
        return dp(0, 0, 0, s, memo);
    }
};