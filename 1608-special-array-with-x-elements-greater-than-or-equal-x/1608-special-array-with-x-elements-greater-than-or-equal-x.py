class Solution:
    def get_first_greater_or_equal(self, nums: List[int], val: int) -> int:
        start, end = 0, len(nums) - 1
        i = len(nums)
        
        while start <= end:
            mid = (start + end) >> 1
            if nums[mid] >= val:
                i = mid
                end = mid - 1
            else:
                start = mid + 1
                
        return i
    
    def specialArray(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        
        for i in range(1, n + 1):
            k = self.get_first_greater_or_equal(nums, i)
            
            if n - k == i:
                return i
            
        return -1