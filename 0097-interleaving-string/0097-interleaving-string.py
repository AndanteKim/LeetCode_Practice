class Solution:
    def dp(self, s1: str, i: int, s2: str, j: int, s3: str, k: int, memo: List[List[int]]) -> bool:
        if i == self.n1:
            return s2[j:] == s3[k:]
        if j == self.n2:
            return s1[i:] == s3[k:]
        if memo[i][j] >= 0:
            return True if memo[i][j] else False
        ans = False
        if (s1[i] == s3[k] and self.dp(s1, i + 1, s2, j, s3, k + 1, memo)) or (s2[j] == s3[k] and self.dp(s1, i, s2, j + 1, s3, k + 1, memo)):
            ans = True
        memo[i][j] = 1 if ans else 0
        return ans
    
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        self.n1, self.n2, self.n3 = len(s1), len(s2), len(s3)
        
        if self.n1 + self.n2 != self.n3:
            return False
        
        memo = [[-1] * self.n2 for _ in range(self.n1)]
        
        return self.dp(s1, 0, s2, 0, s3, 0, memo)