class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        n, left, ans, remain = len(nums), 0, 0, k
        
        for right in range(n):
            remain -= 1 if nums[right] == 0 else 0
            while left <= right and remain < 0:
                remain += 1 if nums[left] == 0 else 0
                left += 1
            ans = max(ans, right - left + 1)
            
        return ans