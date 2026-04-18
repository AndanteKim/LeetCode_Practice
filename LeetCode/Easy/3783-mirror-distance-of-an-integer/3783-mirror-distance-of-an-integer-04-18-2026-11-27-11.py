class Solution:
    def mirrorDistance(self, n: int) -> int:
        def rev(y: int) -> int:
            x = 0
            while y > 0:
                x = x * 10 + y % 10
                y //= 10

            return x
        
        return abs(n - rev(n))