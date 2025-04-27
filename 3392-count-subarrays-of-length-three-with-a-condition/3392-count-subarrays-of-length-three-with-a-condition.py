class Solution:
    def countSubarrays(self, nums: List[int]) -> int:
        ans, n = 0, len(nums)

        for i in range(n - 2):
            if nums[i + 1] == (nums[i] + nums[i + 2]) * 2:
                ans += 1
        
        return ans