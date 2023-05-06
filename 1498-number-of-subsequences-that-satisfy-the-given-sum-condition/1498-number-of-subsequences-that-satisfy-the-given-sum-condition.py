class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        nums.sort()
        mod = 10 ** 9 + 7
        ans = 0
        left, right = 0, len(nums) - 1
        
        while left <= right:
            if nums[left] + nums[right] <= target:
                ans = (ans + (1 << right - left) % mod) % mod;
                left += 1
            else:
                right -= 1
        return ans
        