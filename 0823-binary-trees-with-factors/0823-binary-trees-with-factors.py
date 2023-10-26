class Solution:
    def numFactoredBinaryTrees(self, arr: List[int]) -> int:
        arr.sort()
        MOD = 1_000_000_007
        n = len(arr)
        dp = [1] * n
        index = {x: i for i, x in enumerate(arr)}
        
        for i, x in enumerate(arr):
            for j in range(i):
                # where arr[j] is left child
                if x % arr[j] == 0:
                    right = x // arr[j]
                    if right in index:
                        dp[i] += dp[j] * dp[index[right]]
                        dp[i] %= MOD
        
        return sum(dp) % MOD