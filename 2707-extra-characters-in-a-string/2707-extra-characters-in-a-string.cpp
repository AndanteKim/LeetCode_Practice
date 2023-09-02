class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        unordered_set<string> dictSet(dictionary.begin(), dictionary.end());
        vector<int> dp(n + 1);
        
        for (int start = n - 1; start >= 0; --start){
            dp[start] = dp[start + 1] + 1;
            for (int end = start; end < n; ++end){
                string curr = s.substr(start, end - start + 1);
                if (dictSet.count(curr)) dp[start] = min(dp[start], dp[end + 1]);
            }
        }
        
        return dp[0];
    }
};