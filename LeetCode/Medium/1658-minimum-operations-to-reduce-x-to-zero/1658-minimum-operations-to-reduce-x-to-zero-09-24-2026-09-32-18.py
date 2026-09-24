class Solution:
    def minOperations(self, nums: list[int], x: int) -> int:
        curr, n = sum(nums), len(nums)
        mn, left = float('inf'), 0

        for right in range(n):
            curr -= nums[right]

            while curr < x and left <= right:
                curr += nums[left]
                left += 1
            
            if curr == x:
                mn = min(mn, (n - 1 - right) + left)
        
        return mn if mn != float('inf') else -1