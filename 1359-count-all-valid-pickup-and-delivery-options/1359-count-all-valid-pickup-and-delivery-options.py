class Solution:
    def countOrders(self, n: int) -> int:
        @lru_cache(maxsize = None)
        def dp(unpicked: int, undelivered: int) -> int:
            if not unpicked and not undelivered:
                # completed all orders
                return 1
            
            if unpicked < 0 or undelivered < 0 or undelivered < unpicked:
                # pick-up should be larger or equal to undelivered since undelivered cannot surpass
                # pick-up based on the rule
                return 0
            
            # count all choices of picking up an order
            ans = unpicked * dp(unpicked - 1, undelivered)
            ans %= MOD
            
            # count all choices of delivering a picked order
            ans += (undelivered - unpicked) * dp(unpicked, undelivered - 1)
            ans %= MOD
            
            return ans
        
        MOD = 1_000_000_007
        return dp(n, n)