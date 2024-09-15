class Solution:
    def mySqrt(self, x: int) -> int:
        for i in range(x + 1):
            if i * i >= x:
                if i * i == x:
                    return i
                return i - 1
            
        return -1