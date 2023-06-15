class Solution:
    def findMissingRanges(self, nums: List[int], lower: int, upper: int) -> List[List[int]]:
        if not nums:
            return [[lower, upper]]
        ans, i = [], 0
        
        if nums[0] - lower >= 1:
            ans.append([lower, nums[0] - 1])
        for i in range(len(nums) - 1):
            if nums[i + 1] - nums[i] > 1:
                ans.append([nums[i] + 1, nums[i + 1] - 1])
        if upper - nums[-1] >= 1:
            ans.append([nums[-1] + 1, upper])
                
        return ans