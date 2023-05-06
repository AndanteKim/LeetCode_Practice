class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        nums.sort()
        mod = 10 ** 9 + 7
        ans, n = 0, len(nums)
        left, right = 0, n - 1
        
        while left <= right:
            if nums[left] + nums[right] <= target:
                ans = (ans + 2 ** (right - left)) % mod
                left += 1
            else:
                right -= 1
        return ans
        