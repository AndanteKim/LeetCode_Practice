class Solution {
private:
    bool dp(int i, string& s, vector<string>& wordDict, vector<int>& memo){
        if (i < 0) return true;
        if (memo[i] != -1) return memo[i] == 1;
        
        for (string& word : wordDict){
            int currSize = word.size();
            if (i - currSize + 1 < 0) continue;
            if (s.substr(i - currSize + 1, currSize) == word && dp(i - currSize, s, wordDict, memo)){
                memo[i] = 1;
                return true;
            }
        }
        
        memo[i] = 0;
        return false;
    }
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        vector<int> memo(s.size(), -1);
        return dp(s.size() - 1, s, wordDict, memo);
    }
};