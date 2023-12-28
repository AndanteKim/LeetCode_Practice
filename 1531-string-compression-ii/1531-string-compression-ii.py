class Solution:
    def getLengthOfOptimalCompression(self, s: str, k: int) -> int:
        def digits(x: int) -> int:
            return 1 if x == 1 else 2 if 1 < x < 10 else 3 if 10 <= x < 100 else 4
        
        n = len(s)
        dp = [[float('inf')] * (k + 1) for _ in range(n + 1)]
        dp[0][0] = 0
        
        for i in range(1, n + 1):
            for j in range(min(i, k) + 1):
                if j > 0:
                    dp[i][j] = dp[i - 1][j - 1]
                
                remove = count = 0
                for left in range(i, 0, -1):
                    if s[left - 1] == s[i - 1]:
                        count += 1
                    else:
                        remove += 1
                        if remove > j:
                            break
                    
                    dp[i][j] = min(dp[i][j], dp[left - 1][j - remove] + digits(count))
        
        return dp[-1][-1]
                