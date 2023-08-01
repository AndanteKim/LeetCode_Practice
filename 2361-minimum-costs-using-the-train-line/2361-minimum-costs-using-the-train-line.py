class Solution:
    def solve(self, i: int, lane: int, dp: List[List[int]], regular: List[int], express: List[int], expressCost: int) -> int:
        if i < 0:
            return 0
        
        if dp[i][lane] != -1:
            return dp[i][lane]
        
        regularLane = regular[i] + self.solve(i - 1, 1, dp, regular, express, expressCost)
        expressLane = expressCost + express[i] + self.solve(i - 1, 0, dp, regular, express, expressCost) if lane else express[i] + self.solve(i - 1, 0, dp, regular, express, expressCost)
        
        dp[i][lane] = min(regularLane, expressLane)
        return dp[i][lane]
    
    def minimumCosts(self, regular: List[int], express: List[int], expressCost: int) -> List[int]:
        n = len(regular)
        dp = [[-1] * 2 for _ in range(n)]
        
        self.solve(n - 1, 1, dp, regular, express, expressCost)
        ans = []
        for i in range(n):
            ans.append(dp[i][1])
        
        return ans