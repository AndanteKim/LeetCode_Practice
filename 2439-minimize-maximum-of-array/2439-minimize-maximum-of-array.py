class Solution:
    def is_valid(self, x: int, nums: List[int]) -> bool:
        total = 0
        for i in range(len(nums)):
            total += nums[i]
            if total > x * (i + 1):
                return False
        return True
    
    def minimizeArrayValue(self, nums: List[int]) -> int:
        left, right = 0, max(nums)
        
        while left < right:
            mid = (left + right) >> 1
            
            if (self.is_valid(mid, nums)):
                right = mid
            else:
                left = mid + 1
        return left