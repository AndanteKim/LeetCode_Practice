class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        i, ans = len(s) - 1, 0
        
        while i >= 0 and s[i] == ' ':
            i -= 1
        
        while i >= 0 and (65 <= ord(s[i]) <= 90 or 97 <= ord(s[i]) <= 122):
            ans += 1
            i -= 1
            
        return ans;