class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        ans = [-1] * len(nums)
        
        if k == 0:
            return nums
        
        n = len(nums)
        if 2 * k + 1 > n:
            return ans
        
        window_sum = sum(nums[: 2 * k + 1])
        ans[k] = window_sum // (2 * k + 1)
        
        for i in range(2 * k + 1, n):
            window_sum = window_sum - nums[i - (2 * k + 1)] + nums[i]
            ans[i - k] = window_sum // (2 * k + 1)
    
        return ans