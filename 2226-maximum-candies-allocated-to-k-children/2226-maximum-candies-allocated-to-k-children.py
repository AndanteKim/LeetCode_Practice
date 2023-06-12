class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        
        left, right = 0, sum(candies) // k
        
        while left < right:
            mid, portion = (left + right + 1) >> 1, 0
            
            for candy in candies:
                portion += candy // mid
    
            if portion < k:
                right = mid - 1
            else:
                left = mid
            
        return left