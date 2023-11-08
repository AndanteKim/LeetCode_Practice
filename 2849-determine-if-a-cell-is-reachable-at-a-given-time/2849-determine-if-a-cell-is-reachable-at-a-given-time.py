class Solution:
    def isReachableAtTime(self, sx: int, sy: int, fx: int, fy: int, t: int) -> bool:
        width, height = abs(fx - sx), abs(fy - sy)
        
        if width == 0 and height == 0 and t == 1:
            return False
        # Chebyshev Distance
        return t >= max(width, height)