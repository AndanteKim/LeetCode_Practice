class Solution:
    def scoreOfString(self, s: str) -> int:
        ans, n = 0, len(s) 
        for i in range(n - 1):
            ans += abs(ord(s[i]) - ord(s[i + 1]))
            
        return ans