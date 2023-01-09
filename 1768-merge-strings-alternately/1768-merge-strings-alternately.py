class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        ans, n = "", 0
        for w1, w2 in zip(word1, word2):
            ans += w1+w2
            n += 1
        for i in range(n, max(len(word1), len(word2))):
            if len(word1) > len(word2):
                ans += word1[i]
            else:
                ans += word2[i]
        
        return ans