class Solution:
    def minimumCosts(self, regular: list[int], express: list[int], expressCost: int) -> list[int]:
        n = len(regular)
        dp = [[0] * 2 for _ in range(n + 1)]
        dp[0][0], dp[0][1] = expressCost, 0
        ans = []

        for i in range(1, n + 1):
            # [i][0]: express lane, [i][1]: regular lane
            dp[i][1] = regular[i - 1] + min(dp[i - 1][1], dp[i - 1][0])
            dp[i][0] = express[i - 1] + min(expressCost + dp[i - 1][1], dp[i - 1][0])

            ans.append(min(dp[i][0], dp[i][1]))

        return ans