class Solution:
    def profitableSchemes(self, n: int, minProfit: int, group: List[int], profits: List[int]) -> int:
        mod = int(1e9 + 7)
        dp = [[[0] * 101 for _ in range(101)] for __ in range(101)]
        
        for count in range(n + 1):
            dp[len(group)][count][minProfit] = 1
        
        for index in range(len(group) - 1, -1, -1):
            for count in range(n + 1):
                for profit in range(minProfit + 1):
                    dp[index][count][profit] = dp[index + 1][count][profit]
                    if count + group[index] <= n:
                        dp[index][count][profit] = (dp[index][count][profit] + dp[index + 1][count + group[index]]
                                                   [min(minProfit, profit + profits[index])]) % mod
        return dp[0][0][0]