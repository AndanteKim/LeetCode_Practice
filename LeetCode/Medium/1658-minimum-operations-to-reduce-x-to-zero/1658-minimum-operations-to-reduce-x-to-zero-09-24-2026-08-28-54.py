class Solution:
    def minOperations(self, nums: list[int], x: int) -> int:
        total, n = sum(nums), len(nums)
        left, curr, longest = 0, 0, -1

        for right in range(n):
            curr += nums[right]

            while left <= right and curr > total - x:
                curr -= nums[left]
                left += 1
            
            if curr == total - x:
                longest = max(longest, right - left + 1)
        
        return n - longest if longest != -1 else -1