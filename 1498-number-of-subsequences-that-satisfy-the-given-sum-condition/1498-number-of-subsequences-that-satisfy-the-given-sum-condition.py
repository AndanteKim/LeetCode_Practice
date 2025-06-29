class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        nums.sort()
        ans, n, mod = 0, len(nums), 10 ** 9 + 7

        for left in range(n):
            # Find the insertion position for 'target - nums[left]'
            # 'right' equals the insertion index minus - 1
            right = bisect_right(nums, target - nums[left]) - 1

            if right >= left:
                ans += 2 ** (right - left) % mod

        return ans % mod