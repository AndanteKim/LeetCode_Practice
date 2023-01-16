class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        length_s, length_t = len(s), len(t)
        i, j = 0, 0
        while i < length_s and j < length_t:
            if s[i] == t[j]:
                i += 1
                j += 1
            else:
                j += 1
                
        return True if i == length_s else False
        
        