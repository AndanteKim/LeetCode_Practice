class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        i, len1, j, len2 = 0, len(word1), 0, len(word2)
        
        ans = ""
        while i < len1 or j < len2:
            if i < len1:
                ans += word1[i]
                i += 1
            
            if j < len2:
                ans += word2[j]
                j += 1
        
        return ans