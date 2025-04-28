class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        ans, n = 0, len(nums)
        curr, left = 0, 0
        for right in range(n):
            curr += nums[right]
            
            while left <= right and curr * (right - left + 1) >= k:
                curr -= nums[left]
                left += 1

            length = right - left + 1
            ans += length

        return ans