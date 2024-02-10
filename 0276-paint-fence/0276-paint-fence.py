class Solution:
    def numWays(self, n: int, k: int) -> int:
        # Space Optimization with Tabulation
        if n == 1:
            return k
        
        if n == 2:
            return k * k
        
        two_posts_back, one_post_back = k, k * k
        for i in range(3, n + 1):
            curr = (k - 1) * (one_post_back + two_posts_back)
            two_posts_back, one_post_back = one_post_back, curr
            
        return one_post_back