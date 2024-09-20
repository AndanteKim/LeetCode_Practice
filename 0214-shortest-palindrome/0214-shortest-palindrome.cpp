class Solution {
public:
    string shortestPalindrome(string s) {
        // Base case
        if (s.empty()) return "";
        
        // Find the longest palindromic prefix
        int left = 0, n = s.size();
        for (int right = n - 1; right >= 0; --right){
            if (s[left] == s[right])
                ++left;
        }
        
        // If the whole string is a palindrome, return the original string
        if (left == n)
            return s;
        
        // Extract the suffix that is not part of the palindromic prefix
        string nonPalindromicSuffix = s.substr(left);
        string reverseSuffix = nonPalindromicSuffix;
        reverse(reverseSuffix.begin(), reverseSuffix.end());
        
        return reverseSuffix + shortestPalindrome(s.substr(0, left)) + nonPalindromicSuffix;
    }
};