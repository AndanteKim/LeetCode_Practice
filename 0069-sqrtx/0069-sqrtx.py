from math import e, log

class Solution:
    def mySqrt(self, x: int) -> int:
        if x < 2:
            return x
        
        left = int(e ** (0.5 * log(x)))
        right = left + 1
        return left if right * right > x else right