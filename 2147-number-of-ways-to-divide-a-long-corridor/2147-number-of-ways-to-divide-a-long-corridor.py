class Solution:
    def numberOfWays(self, corridor: str) -> int:
        # Count the number of ways to divide from "index" to the last index with "seats" number of "S" in the current section
        def count(i: int, seats: int) -> int:
            if i == len(corridor):
                return 1 if seats == 2 else 0
            
            if memo[i][seats] != -1:
                return memo[i][seats]
            
            if seats == 2:
                if corridor[i] == "S":
                    ans = count(i + 1, 1)
                else:
                    ans = (count(i + 1, 0) + count(i + 1, 2)) % MOD
            else:
                if corridor[i] == "S":
                    ans = count(i + 1, seats + 1)
                else:
                    ans = count(i + 1, seats)
            
            memo[i][seats] = ans
            return memo[i][seats]
        
        MOD = 1_000_000_007
        memo = [[-1] * 3 for _ in range(len(corridor))]
        return count(0, 0)