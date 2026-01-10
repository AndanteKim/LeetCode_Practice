class Solution {
private:
    int dp(int i, int j, string& s1, string& s2, vector<vector<int>>& memo) {
        // Base case
        if (i < 0 && j < 0) return 0;

        if (i < 0) return (int)s2[j] + dp(i, j - 1, s1, s2, memo);
        if (j < 0) return (int)s1[i] + dp(i - 1, j, s1, s2, memo);

        if (memo[i][j] != -1) return memo[i][j];

        if (s1[i] == s2[j])
            memo[i][j] = dp(i - 1, j - 1, s1, s2, memo);
        else {
            memo[i][j] = min(
                (int)s1[i] + dp(i - 1, j, s1, s2, memo),
                (int)s2[j] + dp(i, j - 1, s1, s2, memo)
            );
        }

        return memo[i][j];
    }

public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector memo(m, vector<int>(n, -1));

        return dp(m - 1, n - 1, s1, s2, memo);
    }
};