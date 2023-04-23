class Solution {
    int m, n;
    int mod = pow(10, 9) + 7;
    
public:
    int numberOfArrays(string s, int k) {
        int m = s.size(), n = to_string(k).size();
        vector<int> dp(m + 1, 0);
        dp[0] = 1;
        for (int start = 0; start < m; ++start){
            if (s[start] == '0') continue;
            int count = 0;
            for (int end = start; end < m; ++end){
                string currNumber = s.substr(start, end - start + 1);
                if (stol(currNumber) > k) break;
                dp[end + 1] = (dp[end + 1] + dp[start]) % mod;
            }
        }
        
        return dp.back();
    }
};