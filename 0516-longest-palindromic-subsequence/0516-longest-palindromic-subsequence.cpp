class Solution {
    int lps(int left, int right, string& s, vector<vector<int>>& memo){
        if (memo[left][right] != 0) return memo[left][right];
        if (left > right) return 0;
        if (left == right) return 1;
        
        if (s[left] == s[right]) memo[left][right] = lps(left + 1, right - 1, s, memo) + 2;
        else memo[left][right] = max(lps(left, right - 1, s, memo), lps(left + 1, right, s, memo));
        
        return memo[left][right];
    }
    
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> memo(n, vector<int>(n));
        return lps(0, s.size() - 1, s, memo);
    }
};