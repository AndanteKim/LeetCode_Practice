class Solution:
    # Helper function to build KMP prefix table
    def _build_prefix_table(self, s: str) -> List[int]:
        prefix_table, length = [0] * len(s), 0
        
        # Build the table by comparing characters
        for i in range(1, len(s)):
            while length > 0 and s[i] != s[length]:
                length = prefix_table[length - 1];
            
            if s[i] == s[length]:
                length += 1
            prefix_table[i] = length
            
        return prefix_table
    
    def shortestPalindrome(self, s: str) -> str:
        # KMP(Knuth Morris Pratt) algorithm
        # Reverse the original string
        rev_str = s[::-1]
        
        # Combine the original and reversed strings with a separator
        comb_str = s + '#' + rev_str
        
        # Build the prefix table for the combined string
        prefix_table = self._build_prefix_table(comb_str)
        
        # Get the length of the longest palindromic prefix
        palindrome_len = prefix_table[-1]
        
        # Construct the shortest palindrome by appending the reverse of the suffix
        suffix = rev_str[:len(s) - palindrome_len]
        
        return suffix + s