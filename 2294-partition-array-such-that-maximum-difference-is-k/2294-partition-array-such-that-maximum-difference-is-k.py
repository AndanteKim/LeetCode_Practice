class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans, x = 1, nums[0]
        for i in range(len(nums)):
            if nums[i] - x > k:
                ans += 1
                x = nums[i]
        return ans
            
        