class Solution:
    def subsequencePairCount(self, nums: List[int]) -> int:
        MOD = 1_000_000_007
        m = max(nums)
        dp = [[0] * (m + 1) for _ in range(m + 1)]
        dp[0][0] = 1

        for num in nums:
            ndp = [[0] * (m + 1) for _ in range(m + 1)]

            for j in range(m + 1):
                div1 = gcd(j, num)
                for k in range(m + 1):
                    val = dp[j][k]
                    if val == 0:
                        continue
                    
                    div2 = gcd(k, num)
                    ndp[j][k] = (ndp[j][k] + val) % MOD
                    ndp[div1][k] = (ndp[div1][k] + val) % MOD
                    ndp[j][div2] = (ndp[j][div2] + val) % MOD
            
            dp = ndp
        
        ans = 0

        for j in range(1, m + 1):
            ans = (ans + dp[j][j]) % MOD

        return ans