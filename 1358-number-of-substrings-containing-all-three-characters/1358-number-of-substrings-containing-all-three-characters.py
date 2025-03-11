class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        n, ans = len(s), 0

        # Track last position of a, b, c
        last_pos = [-1] * 3

        for pos in range(n):
            # Update last position of current character
            last_pos[ord(s[pos]) - 97] = pos
            
            # Add count of valid substrings ending at current position
            # If any character is missing, min will be -1
            # Else min gives leftmost required character position
            min_pos = min(last_pos)
            ans += 1 + min_pos
        
        return ans