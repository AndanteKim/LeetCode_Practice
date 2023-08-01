class Solution:
    def minimumCosts(self, regular: List[int], express: List[int], expressCost: int) -> List[int]:
        n, ans = len(regular), []
        dp = [[0] * 2 for _ in range(n + 1)]
        
        dp[0][1] = 0
        dp[0][0] = expressCost
        
        # 1: regular lane, 0: express lane
        for i in range(1, n + 1):
            dp[i][1] = regular[i - 1] + min(dp[i - 1][1], dp[i - 1][0])
            dp[i][0] = express[i - 1] + min(expressCost + dp[i - 1][1], dp[i - 1][0])
            ans.append(min(dp[i][0], dp[i][1]))
        
        return ans