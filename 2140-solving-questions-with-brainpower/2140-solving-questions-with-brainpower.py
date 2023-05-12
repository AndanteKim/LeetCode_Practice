class Solution:
    def dfs(self, i: int, dp: List[int], questions: List[List[int]]) -> int:
        if i >= self.n:
            return 0
        
        if dp[i]:
            return dp[i]
        points, skip = questions[i]
        
        dp[i] = max(self.dfs(i + 1, dp, questions), points + self.dfs(i + skip + 1, dp, questions))
        
        return dp[i]
    
    def mostPoints(self, questions: List[List[int]]) -> int:
        self.n = len(questions)
        dp = [0] * self.n
        
        return self.dfs(0, dp, questions)