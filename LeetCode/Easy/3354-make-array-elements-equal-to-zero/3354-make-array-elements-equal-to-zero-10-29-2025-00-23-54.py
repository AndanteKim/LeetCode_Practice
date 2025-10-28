class Solution:
    def countValidSelections(self, nums: List[int]) -> int:
        n, ans = len(nums), 0
        total = sum(nums)
        left, right = 0, total

        for curr in range(n):
            if nums[curr] == 0:
                if abs(left - right) == 0:
                    ans += 2
                elif abs(left - right) == 1:
                    ans += 1
            else:
                left += nums[curr]
                right -= nums[curr]

        return ans