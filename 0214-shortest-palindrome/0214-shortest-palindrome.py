class Solution:
    def shortestPalindrome(self, s: str) -> str:
        n = len(s)
        # Reverse the string
        rev_str = s[::-1]
        
        # Iterate through the string to find the longest palindromic prefix
        for i in range(n):
            if s[:n - i] == rev_str[i:]:
                return rev_str[:i] + s
            
        return ""