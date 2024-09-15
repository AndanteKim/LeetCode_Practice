class Solution:
    def mySqrt(self, x: int) -> int:
        # Binary search
        left, right = 0, x
        
        while left <= right:
            mid = (left + right) >> 1
            
            if mid * mid <= x:
                left = mid + 1
            else:
                right = mid - 1
                
        return right