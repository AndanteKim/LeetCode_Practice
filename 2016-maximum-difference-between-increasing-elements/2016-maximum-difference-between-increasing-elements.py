class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        ans, n = -1, len(nums)
        for i in range(n - 1):
            for j in range(i + 1, n):
                if nums[j] != nums[i]:
                    ans = max(ans, nums[j] - nums[i])
        
        return ans