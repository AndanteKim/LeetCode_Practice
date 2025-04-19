class Solution:
    def countPairs(self, nums: List[int], target: int) -> int:
        ans, n = 0, len(nums)

        for i in range(n - 1):
            for j in range(i + 1, n):
                if nums[i] + nums[j] < target:
                    ans += 1

        return ans