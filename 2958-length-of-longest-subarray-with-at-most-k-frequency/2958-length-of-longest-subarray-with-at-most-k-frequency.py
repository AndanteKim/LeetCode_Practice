class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        ans, n, freq = 0, len(nums), dict()
        left = 0

        for right in range(n):
            freq[nums[right]] = freq.get(nums[right], 0) + 1

            while right - left >= k and freq[nums[right]] > k:
                freq[nums[left]] -= 1
                left += 1
            ans = max(ans, right - left + 1)

        return ans