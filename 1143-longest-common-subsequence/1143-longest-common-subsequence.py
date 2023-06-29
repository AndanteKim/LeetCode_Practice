class Solution:
    def dp(self, i: int, j: int, text1: str, text2: str, memo: Dict[Tuple[int, int], int]) -> int:
        if i == len(text1) or j == len(text2):
            return 0
        
        if memo[(i, j)] != -1:
            return memo[(i, j)]
        
        if text1[i] == text2[j]:
            ans = 1 + self.dp(i + 1, j + 1, text1, text2, memo)
        else:
            ans = max(self.dp(i + 1, j, text1, text2, memo), self.dp(i, j + 1, text1, text2, memo))
        
        memo[(i, j)] = ans
        return ans
    
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        memo = defaultdict(lambda: -1)
        return self.dp(0, 0, text1, text2, memo)
    