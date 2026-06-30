class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        # Track the last position of a, b, c
        ans, last_pos = 0, [-1] * 3
        
        for pos in range(len(s)):
            last_pos[ord(s[pos]) - 97] = pos

            # Add count of valid substrings ending at current position
            ans += 1 + min(last_pos)

        return ans