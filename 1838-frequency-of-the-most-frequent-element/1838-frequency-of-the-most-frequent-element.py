class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        nums.sort()
        n, left, ans, curr = len(nums), 0, 0, 0
        
        for right in range(n):
            target = nums[right]
            curr += target
            
            while (right - left + 1) * target - curr > k:
                curr -= nums[left]
                left += 1
            
            ans = max(ans, right - left + 1)
        return ans