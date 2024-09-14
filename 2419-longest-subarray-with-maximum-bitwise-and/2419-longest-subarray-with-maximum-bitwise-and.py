class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        ans, left, n, k = 0, 0, len(nums), 0
        seen = defaultdict(int)
        
        for right in range(n):
            k = max(k, nums[right])
            
            while left < right and (nums[left] & nums[right]) < k:
                left += 1
            
            if k == nums[right]:
                ans = max(seen[k], right - left + 1)
                seen[k] = max(seen[k], right - left + 1)
            
        return ans