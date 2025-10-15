class Solution:
    def cheapestJump(self, coins: List[int], maxJump: int) -> List[int]:
        n = len(coins)
        dp, path = [float('inf')] * n, [[] for _ in range(n)]
        dp[0], path[0] = 0, [1]
    
        for i in range(1, n):
            if coins[i] == -1:
                continue
            for j in range(max(0, i - maxJump), i):
                if dp[i] > (coins[i] + dp[j]):
                    path[i] = path[j] + [i + 1]
                    dp[i] = coins[i] + dp[j]
                elif dp[i] == (coins[i] + dp[j]):
                    if path[i] > path[j] + [i + 1]:
                        path[i] = path[j] + [i + 1]

        return path[n - 1]