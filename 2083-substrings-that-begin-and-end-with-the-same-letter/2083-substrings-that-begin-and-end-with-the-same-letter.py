class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        n = len(s)
        ans, prefix_count = 0, [0] * 26
        
        for i in range(len(s)):
            # Increment the number of times we encountered the current letter so far.
            prefix_count[ord(s[i]) - 97] += 1
            
            # Current letter can be paired with all the occurrences of it that
            # comes before, including itself, to form a valid substring.
            ans += prefix_count[ord(s[i]) - 97]
        
        return ans