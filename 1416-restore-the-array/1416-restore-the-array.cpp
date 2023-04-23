class Solution {
    int m, n;
    int mod = pow(10, 9) + 7;
    
    int dfs(int start, string& s, int k, vector<int>& dp){
        if (dp[start] != 0)
            return dp[start];
        if (start == m) return 1;
        if (s[start] == '0') return 0;
        int count = 0;
        for (int end = start; end < m; ++end){
            string currNumber = s.substr(start, end - start + 1);
            if (stol(currNumber) > k) break;
            count = (count + dfs(end + 1, s, k, dp)) % mod;
        }
        dp[start] = count % mod;
        return count;
    }
    
public:
    int numberOfArrays(string s, int k) {
        m = s.size();
        n = to_string(k).size();
        vector<int> dp(m + 1, 0);
        return dfs(0, s, k, dp) % mod;
    }
};