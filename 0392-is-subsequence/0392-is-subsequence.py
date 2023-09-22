class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if not s:
            return True
        i, len_s = 0, len(s)
        
        for c in t:
            if c == s[i]:
                i += 1
                if i == len_s:
                    return True
        
        return False