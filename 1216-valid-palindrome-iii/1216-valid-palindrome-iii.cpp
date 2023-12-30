class Solution {
    int n;
    // Used overloading
    int isValidPalindrome(string& s, int i, int j, vector<vector<int>>& memo){
        // Base case: only 1 character remaining
        if (i == j)
            return 0;
        
        // Base case 2: only 2 characters remaining
        if (i == j - 1)
            return s[i] != s[j];
        
        // Return the precomputed value if exists as memoization
        if (memo[i][j] != -1)
            return memo[i][j];
        
        
        // Case 1: If character at 'i' equals character at 'j'
        if (s[i] == s[j])
            return memo[i][j] = isValidPalindrome(s, i + 1, j - 1, memo);
        
        // Case 2: If character at 'i' does not equal to character at 'j'.
        // Either delete character at 'i' or delete character at 'j'
        // and try to match the two pointers using recursion.
        // We need to take the minimum of the two results and add 1
        // representing the cost of deletion.
        
        return memo[i][j] = 1 + min(isValidPalindrome(s, i + 1, j, memo), isValidPalindrome(s, i, j - 1, memo));
    }
    
public:
    bool isValidPalindrome(string s, int k) {
        this -> n = s.size();
        vector memo(n, vector<int>(n, -1));
        
        // Return true if the minimum cost to create a palindrome by only deleting the letters
        // is less than or equal to 'k'.
        return isValidPalindrome(s, 0, n - 1, memo) <= k;
    }
};