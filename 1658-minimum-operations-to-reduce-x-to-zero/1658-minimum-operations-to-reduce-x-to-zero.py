class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        n = len(nums)
        total, left = sum(nums), 0
        curr, target, ans = 0, total - x, float('inf')
        
        for right in range(n):
            curr += nums[right]
            while left <= right and curr > target:
                curr -= nums[left]
                left += 1
            if curr == target:
                ans = min(ans, n - 1 - (right - left))
        return -1 if ans == float('inf') else ans