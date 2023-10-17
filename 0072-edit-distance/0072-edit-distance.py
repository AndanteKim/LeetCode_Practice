class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        @lru_cache(maxsize = None)
        def dp(i: int, j: int) -> int:
            if i == 0:
                return j
            if j == 0:
                return i
            
            operations = 0
            if word1[i - 1] == word2[j - 1]:
                operations = dp(i - 1, j - 1)
            else:
                operations = 1 + min(dp(i - 1, j), dp(i, j - 1), dp(i - 1, j - 1))
            
            return operations
        
        
        n1, n2 = len(word1), len(word2)
        return dp(n1, n2)