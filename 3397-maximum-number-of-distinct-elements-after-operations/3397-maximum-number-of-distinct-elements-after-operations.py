class Solution:
    def maxDistinctElements(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans, prev = 0, float('-inf')

        for num in nums:
            curr = min(max(prev + 1, num - k), num + k)
            if curr > prev:
                prev = curr
                ans += 1

        return ans