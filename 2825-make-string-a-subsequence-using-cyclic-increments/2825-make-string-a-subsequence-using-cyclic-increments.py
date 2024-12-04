class Solution:
    def canMakeSubsequence(self, str1: str, str2: str) -> bool:
        m, j = len(str2), 0
        
        for c in str1:
            if 0 <= ord(str2[j]) - ord(c) <= 1 or ord(c) - ord(str2[j]) == 25:
                j += 1
            
            if j >= m:
                return True
        
        return False   