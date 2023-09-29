class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        if len(nums) == 1:
            return True
        
        n, increasing, decreasing = len(nums), False, False
        for i in range(n - 1):
            if nums[i] <= nums[i + 1]:
                if i == n - 2:
                    increasing = True
            else:
                break
        
        for i in range(n - 1):
            if nums[i] >= nums[i + 1]:
                if i == n - 2:
                    decreasing = True
            else:
                break
        
        return increasing or decreasing