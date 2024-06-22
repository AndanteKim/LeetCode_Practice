class Solution:
    def numberOfSpecialSubstrings(self, s: str) -> int:
        curr, start, ans = [0] * 26, 0, 0
        
        for end in range(len(s)):
            while curr[ord(s[end]) - 97] == 1:
                curr[ord(s[start]) - 97] -= 1
                start += 1
            
            curr[ord(s[end]) - 97] += 1
            ans += end - start + 1
            
        return ans
            