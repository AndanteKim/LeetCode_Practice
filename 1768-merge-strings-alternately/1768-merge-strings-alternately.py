class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        ans, i, j = "", 0, 0
        length1, length2 = len(word1), len(word2)
        while i < length1 or j < length2:
            if i < length1:
                ans += word1[i]
                i += 1
            if j < length2:
                ans += word2[j]
                j += 1
        
        return ans