class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        nums.sort()
        
        for num in nums:
            if bisect_right(nums, num) - bisect_left(nums, num) > 1:
                return num
            
        return -1