class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:
        nums.sort()
        ans, freqs, n = 0, Counter(nums), len(nums)
        
        for i in range(nums[0], nums[-1] + 1):
            left = bisect_left(nums, i - k)
            right = bisect_right(nums, i + k)

            curr = min(right - left, freqs.get(i, 0) + numOperations)
            ans = max(ans, curr)

        return ans