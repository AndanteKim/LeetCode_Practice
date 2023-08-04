class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n);
        
        for (int i = 0; i < n; ++i){
            for (string& word : wordDict){
                if (i < word.size() - 1) continue;
                if (i == word.size() - 1 || dp[i - word.size()]){
                    if (s.substr(i - word.size() + 1, word.size()) == word){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        
        return dp.back();
    }
};