class Solution:
    def maxSum(self, nums: List[int]) -> int:
        ans, seen = max(nums), set()

        for num in nums:
            if num in seen:
                continue
            if num > 0:
                seen.add(num)

        return ans if len(seen) == 0 else sum(seen)