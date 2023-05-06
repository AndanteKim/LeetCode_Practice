class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        nums.sort()
        mod = 10 ** 9 + 7
        ans, n = 0, len(nums)
        for left in range(n):
            right = bisect_right(nums, target - nums[left]) - 1
            if right >= left:
                ans += 2 ** (right - left)
            
        return ans % mod