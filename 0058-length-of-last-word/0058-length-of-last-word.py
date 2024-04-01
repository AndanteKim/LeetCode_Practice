class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        i, ans, count_start = len(s) - 1, 0, False
        while i >= 0:
            if not count_start and s[i] == ' ':
                i -= 1
                continue
            
            if count_start and s[i] == ' ':
                break
            
            count_start = True
            ans += 1
            i -= 1
        
        return ans