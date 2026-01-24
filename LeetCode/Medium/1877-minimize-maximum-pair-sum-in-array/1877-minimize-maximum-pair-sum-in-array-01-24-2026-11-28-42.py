class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        nums.sort()
        n, ans = len(nums), 0
        
        for i in range(n // 2):
            ans = max(ans, nums[i] + nums[n - 1 - i])

        return ans