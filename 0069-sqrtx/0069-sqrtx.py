class Solution:
    def mySqrt(self, x: int) -> int:
        # Binary search
        if x < 2:
            return x
        
        left, right = 0, x
        
        while left <= right:
            mid = (left + right) >> 1
            
            if mid * mid < x:
                left = mid + 1
            elif mid * mid > x:
                right = mid - 1
            else:
                return mid
                
        return right