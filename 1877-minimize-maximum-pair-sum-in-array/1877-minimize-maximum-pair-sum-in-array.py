class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        nums.sort()
        
        i, j, ans = len(nums) // 2 - 1, len(nums) // 2, 0
        while i >= 0 and j < len(nums):
            ans = max(ans, nums[i] + nums[j])
            i -= 1
            j += 1
        
        return ans