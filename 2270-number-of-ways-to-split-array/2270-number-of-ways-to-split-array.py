class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        total = sum(nums)
        curr, ans = 0, 0
        
        for i in range(len(nums)-1):
            curr += nums[i]
            if curr >= total - curr:
                ans += 1
        return ans