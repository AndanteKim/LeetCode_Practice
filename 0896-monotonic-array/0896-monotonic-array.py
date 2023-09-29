class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        inc = dec = False
        
        for i in range(len(nums) - 1):
            if nums[i] < nums[i + 1]:
                inc = True
            if nums[i] > nums[i + 1]:
                dec = True
            
            if inc and dec:
                return False
        return True
            