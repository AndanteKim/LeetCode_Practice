class Solution {
private:
    int digits(int x){
        return (x == 1)? 1 : (1 < x && x < 10)? 2 : (10 <= x && x < 100)? 3 : 4;
    }
    
public:
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        vector dp(n + 1, vector<int>(k + 1, 1e9));
        dp[0][0] = 0;
        
        for (int i = 1; i <= n; ++i){
            for (int j = 0; j <= min(i, k); ++j){
                if (j > 0)
                    dp[i][j] = dp[i - 1][j - 1];
                int count = 0, remove = 0;
                for (int left = i; left > 0; --left){
                    if (s[left - 1] == s[i - 1])
                        ++count;
                    else{
                        ++remove;
                        if (remove > j)
                            break;
                    }
                
                    dp[i][j] = min(dp[i][j], dp[left - 1][j - remove] + digits(count));
                }
            }
        }
        
        return dp.back().back();
    }
};