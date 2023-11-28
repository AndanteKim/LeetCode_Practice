class Solution:
    def numberOfWays(self, corridor: str) -> int:
        MOD, n = 1_000_000_007, len(corridor)
        
        # Base cases
        count = [[0] * 3 for _ in range(n + 1)]
        count[n][2] = 1
        
        for i in range(n - 1, -1, -1):
            if corridor[i] == 'S':
                count[i][0] = count[i + 1][1]
                count[i][1] = count[i + 1][2]
                count[i][2] = count[i + 1][1]
            
            else:
                count[i][0] = count[i + 1][0]
                count[i][1] = count[i + 1][1]
                count[i][2] = (count[i + 1][0] + count[i + 1][2]) % MOD
        
        return count[0][0]