class Solution:
    def longestRepeatingSubstring(self, s: str) -> int:
        n, suffixes = len(s), []
        
        # Create suffix array by stroing all suffixes of the string
        for i in range(n):
            suffixes.append(s[i:])
            
        # Sort the suffix array
        suffixes.sort()
        max_len = 0
        
        # Compare adjacent suffixes to find the longest common prefix
        for i in range(1, n):
            j = 0
            
            # Compare characters one by one until
            # they differ or end of one suffix is reached
            while (j < min(len(suffixes[i]), len(suffixes[i - 1])) and suffixes[i][j]  == suffixes[i - 1][j]):
                j += 1
                
            # Update max_length with the length of the common prefix
            max_len = max(max_len, j)
            
        return max_len