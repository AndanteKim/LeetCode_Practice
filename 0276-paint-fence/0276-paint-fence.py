class Solution:
    def numWays(self, n: int, k: int) -> int:
        def total_ways(i: int) -> int:
            if i == 1:
                return k
            
            if i == 2:
                return k * k
            
            # Check if we've already calculated totalWays(i)
            if i in memo:
                return memo[i]
            
            # Use the recurrence relation to calculaate total_ways(i)
            memo[i] = (k - 1) * (total_ways(i - 1) + total_ways(i - 2))
            return memo[i]
        
        memo = dict()
        return total_ways(n)