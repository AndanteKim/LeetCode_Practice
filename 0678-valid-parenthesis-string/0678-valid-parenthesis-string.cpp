class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        
        // dp[i][j] represents the substring starting index i is valid with opening brackets.
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1));
        // base case: an empty string with 0 opening brackets is valid
        dp[n][0] = true;
        
        for (int index = n - 1; index >= 0; --index){
            for (int openCount = 0; openCount < n; ++openCount){
                bool isValid = false;
                
                // '*' can represent '(', ')' or (empty)
                if (s[index] == '*'){
                    if (index < n)
                        // try * as '('
                        isValid |= dp[index + 1][openCount + 1];
                    
                    // opening brackets to use '*' as ')'
                    if (openCount > 0)
                        // try * as ')'
                        isValid |= dp[index + 1][openCount - 1];
                    // ignore '*'
                    isValid |= dp[index + 1][openCount];
                }
                else{
                    // If the character is not '*', it can be '(' or ')'
                    if (s[index] == '(')
                        // try '('
                        isValid |= dp[index + 1][openCount + 1];
                    else if (openCount > 0)
                        // try ')'
                        isValid |= dp[index + 1][openCount - 1];
                }
                dp[index][openCount] = isValid;
            }
        }
        
        // check if the entire string is valid with no excess opening brackets
        return dp[0][0];
    }
};