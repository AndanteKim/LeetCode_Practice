class Solution {
public:
    bool checkValidString(string s) {
        int openCount = 0, closeCount = 0, n = s.size() - 1;
        
        // Traverse the string from both ends simultaneously
        for (int i = 0; i <= n; ++i){
            // Count open parentheses or asterisks
            if (s[i] == '(' || s[i] == '*'){
                ++openCount;
            }
            else --openCount;
            
            // count close parentheses or asterisks
            if (s[n - i] == ')' || s[n - i] == '*'){
                ++closeCount;
            }
            else --closeCount;
            
            // If at any point open count or close count goes negative, the string is invalid
            if (openCount < 0 || closeCount < 0) return false;
        }
        
        // If open count and close count are both non-negative, the string is valid.
        return true;
    }
};