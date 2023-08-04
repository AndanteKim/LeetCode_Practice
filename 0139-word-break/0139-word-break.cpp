class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1);
        dp[0] = true;
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        
        for (int i = 1; i <= n; ++i){
            for (int j = 0; j < i; ++j){
                if (dp[j] && words.find(s.substr(j, i - j)) != words.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};