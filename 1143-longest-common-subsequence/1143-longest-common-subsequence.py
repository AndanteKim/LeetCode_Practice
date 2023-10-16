class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        @lru_cache(maxsize = None)
        def dp(i: int, j: int) -> int:
            if i >= n1 or j >= n2:
                return 0
            
            longest_seq = 0
            if text1[i] == text2[j]:
                longest_seq = 1 + dp(i + 1, j + 1)
            else:
                longest_seq = max(dp(i + 1, j), dp(i, j + 1))
            
            return longest_seq
        
        n1, n2 = len(text1), len(text2)
        return dp(0, 0)