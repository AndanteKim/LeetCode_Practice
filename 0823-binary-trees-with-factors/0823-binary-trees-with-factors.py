class Solution:
    def numFactoredBinaryTrees(self, arr: List[int]) -> int:
        @lru_cache(maxsize = None)
        def dp(node: int) -> int:
            ans = 1
            for elem in arr_set:
                if node % elem == 0 and node // elem in arr_set:
                    ans += dp(elem) * dp(node // elem)
                    ans %= MOD
            
            return ans
        
        MOD = 1_000_000_007
        arr_set = set(arr)
        
        return sum(dp(x) for x in arr_set) % MOD