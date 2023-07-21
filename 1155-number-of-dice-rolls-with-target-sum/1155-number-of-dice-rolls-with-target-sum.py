class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        MOD = int(10 ** 9 + 7)
        memo = [[0] * (target + 1) for _ in range(n + 1)]
        memo[n][target] = 1
        
        for diceIndex in range(n - 1, -1, -1):
            for currSum in range(0, target + 1):
                ways = 0
                for i in range(1, min(k, target - currSum) + 1):
                    ways = (ways + memo[diceIndex + 1][currSum + i]) % MOD
                
                memo[diceIndex][currSum] = ways
        
        return memo[0][0]
        