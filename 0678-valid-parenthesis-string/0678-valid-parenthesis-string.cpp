class Solution {
private:
    int n;
    bool isValidString(int index, int openCount, const string& s, vector<vector<int>>& memo){
        // base case: If reached the end of the string, check if all brackets are balanced
        if (index == n)
            return openCount == 0;
        
        // If already computed, return memoized result
        if (memo[index][openCount] != -1)
            return memo[index][openCount];
        
        bool isValid = false;
        // If encountering '*', try all possibilities.
        if (s[index] == '*'){
            // Treat * as '('
            isValid |= isValidString(index + 1, openCount + 1, s, memo);
            // Treat * as ')'
            if (openCount)
                isValid |= isValidString(index + 1, openCount - 1, s, memo);
            
            // Treat * as empty
            isValid |= isValidString(index + 1, openCount, s, memo);
        }
        else{
            // Handle '(' and ')'
            // Increment count for '('
            if (s[index] == '(')
                isValid = isValidString(index + 1, openCount + 1, s, memo);
            // Decrement count for ')'
            else if (openCount)
                isValid = isValidString(index + 1, openCount - 1, s, memo);
        }
        
        // Memoize and return the result
        return memo[index][openCount] = (isValid)? 1:0;
    }
    
public:
    bool checkValidString(string s) {
        this -> n = s.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        
        return isValidString(0, 0, s, memo);
    }
};