class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int n = s.size();
        vector<int> prevDp(n);
        
        // Generate all combinations of 'i' and 'j' in the correct order
        for (int i = n - 2; i >= 0; --i){
            vector<int> dp(n);
            
            for (int j = i + 1; j < n; ++j){
                // Case 1: Character at 'i' == character at 'j'
                if (s[i] == s[j])
                    dp[j] = prevDp[j - 1];
                // Case 2: Character at 'i' != character at 'j'
                // Either delete character 'i' or 'j' and try to match two pointers
                // We try to take two minimum of results and add 1 representating the cost of deletion 
                else
                    dp[j] = 1 + min(prevDp[j], dp[j - 1]);
            }
            prevDp = dp;
        }
        
        return prevDp[n - 1] <= k;
    }
};