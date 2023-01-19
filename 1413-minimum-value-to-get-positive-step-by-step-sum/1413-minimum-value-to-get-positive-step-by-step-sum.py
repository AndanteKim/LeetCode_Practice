class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        n, m = len(nums), 100
        
        left, right = 1, m*n+1
        
        while left < right:
            mid = (left + right) >> 1
            total = mid
            is_valid = True
            
            for num in nums:
                total += num
                
                if total < 1:
                    is_valid = False
                    break
            
            if is_valid:
                right = mid
            else:
                left = mid + 1
        return left