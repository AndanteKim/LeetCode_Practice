class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int n = s.size();
        vector<int> dp(n);
        
        // To store the previous required values from dp.
        int prev, temp;
        // Generate all combinations 'i' and 'j' in the correct order.
        for (int i = n - 2; i >= 0; --i){
            // 'prev' stores the value at dp[i + 1][j - 1];
            prev = 0;
            for (int j = i + 1; j < n; ++j){
                // Store the value of memo[i + 1][j] temporarily
                temp = dp[j];
                
                // Case 1: Character at 'i' equals character at 'j'
                if (s[i] == s[j])
                    dp[j] = prev;
                
                // Case 2: Character at 'i' doesn't equal character at 'j'.
                // Either delete character at 'i' or delete character at 'j'
                // and try to match the two pointers.
                // We need to take the minimum of the two results and add 1
                // representating the cost of deletion.
                else
                    // dp[j] := contain the value for dp[i + 1][j]
                    // dp[j - 1] := contain the value for dp[i][j - 1]
                    dp[j] = 1 + min(dp[j], dp[j - 1]);
            
                // Copy the value of dp[i + 1][j] to 'prev'
                // For the next iteration when j = j + 1
                // 'prev' will hold the value dp[i + 1][j - 1]
                prev = temp;
            }
        }
        
        // Return true if the minimum cost to create a palindrome by only deleting the letters
        // is less than equal to 'k'.
        return dp[n - 1] <= k;
    }
};