class Solution:
    def subArrayRanges(self, nums: List[int]) -> int:
        n, ans = len(nums), 0
        
        for left in range(n):
            min_val, max_val = float('inf'), float('-inf')
            for right in range(left, n):
                max_val = max(max_val, nums[right])
                min_val = min(min_val, nums[right])
                ans += max_val - min_val
        return ans

        
        