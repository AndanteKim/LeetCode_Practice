class Solution:
    def missingElement(self, nums: List[int], k: int) -> int:
        n = len(nums)
        
        for i in range(1, n):
            gap = nums[i] - nums[i - 1] - 1
            if gap >= k:
                return nums[i - 1] + k
            k -= gap
        
        return nums[n - 1] + k