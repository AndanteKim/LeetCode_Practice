class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        // DP with hashmap
        set<string> dictionary(words.begin(), words.end());
        vector<string> ans;
        
        for (const string& word: words){
            const int n = word.size();
            vector<bool> dp(n+1);
            dp[0] = true;
            
            for (int i = 1; i <= n; ++i){
                for (int j = (i == n? 1 : 0); !dp[i] && j < i; ++j){
                    dp[i] = dp[j] && dictionary.count(word.substr(j, i - j));
                }
            }
            
            if (dp[n]) ans.push_back(word);
        }
        
        return ans;
    }
};