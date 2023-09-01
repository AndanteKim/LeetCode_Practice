class Solution:
    def countBits(self, n: int) -> List[int]:
        ans = [0] * (n + 1)
        x, b = 0, 1
        
        # [0, b) is calculated
        while b <= n:
            # generate [b, 2b) or [b, n) from [0, b)
            while x < b and x + b <= n:
                ans[x + b] = ans[x] + 1
                x += 1
            
            # reset x
            x = 0
            # b = 2b
            b <<= 1
        
        return ans