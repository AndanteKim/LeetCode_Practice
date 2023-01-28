class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        left = cnts = ans = 0
        
        for right in range(len(nums)):
            if nums[right] & 1:
                k -= 1
                cnts = 0
            while k == 0:
                k += nums[left] & 1
                left += 1
                cnts += 1
            ans += cnts
        return ans
                