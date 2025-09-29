class Solution:
    def canDivideIntoSubsequences(self, nums: List[int], k: int) -> bool:
        pre, cnt = nums[0], 0

        for n in nums:
            if pre == n:
                cnt += 1
            else:
                pre, cnt = n, 1

            if cnt * k > len(nums):
                return False

        return True