class Solution:
    def findMissingRanges(self, nums: List[int], lower: int, upper: int) -> List[List[int]]:
        if len(nums) == 0:
            return [[lower, upper]]
        
        ans, n = [[lower, nums[0] - 1]] if lower < nums[0] else [], len(nums)
        
        for i in range(n - 1):
            if abs(nums[i] - nums[i + 1]) <= 1:
                continue 
            ans.append([nums[i] + 1, nums[i + 1] - 1])
        
        if nums[-1] < upper:
            ans.append([nums[-1] + 1, upper])

        return ans