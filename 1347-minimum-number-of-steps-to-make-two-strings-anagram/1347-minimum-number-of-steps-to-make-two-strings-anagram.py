class Solution:
    def minSteps(self, s: str, t: str) -> int:
        s_chars, t_chars = [0] * 26, [0] * 26
        ans, n = 0, len(s)
        
        for i in range(n):
            s_chars[ord(s[i]) - 97] += 1
            t_chars[ord(t[i]) - 97] += 1
            
        for i in range(26):
            ans += abs(s_chars[i] - t_chars[i])
        
            
        return ans // 2