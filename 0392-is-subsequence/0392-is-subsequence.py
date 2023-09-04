class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        i, j, len_s, len_t = 0, 0, len(s), len(t)
        
        while i < len_s and j < len_t:
            if s[i] == t[j]:
                i += 1
                j += 1
            else:
                j += 1
        
        return True if i == len_s else False