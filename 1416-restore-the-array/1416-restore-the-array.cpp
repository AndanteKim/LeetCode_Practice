class Solution {
public:
    int numberOfArrays(string s, int k) {
        int m = s.size(), n = to_string(k).size();
        int mod = pow(10, 9) + 7;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int start = 0; start < m; ++start){
            if (s[start] == '0'){
                dp[start % (n + 1)] = 0;
                continue;
            }
            
            for (int end = start; end < m; ++end){
                string currNumber = s.substr(start, end - start + 1);
                if (stol(currNumber) > k) break;
                dp[(end + 1) % (n + 1)] = (dp[(end + 1) % (n + 1)] + dp[start % (n + 1)]) % mod;
            }
            dp[start % (n + 1)] = 0;
        }
        
        return dp[m % (n + 1)];
    }
};