class Solution:
    def atMost(self, k: int) -> int:
        ans = left = 0
        
        for right in range(len(self.nums)):
            k -= self.nums[right] % 2
            while k < 0:
                k += self.nums[left] % 2
                left += 1
            ans += right - left + 1
        return ans
    
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        self.nums = nums
        
        return self.atMost(k) - self.atMost(k-1)