class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        ans, max_freq, freq = 0, 0, dict()

        for num in nums:
            freq[num] = freq.get(num, 0) + 1
            max_freq = max(max_freq, freq[num])

        for _, f in freq.items():
            if f == max_freq:
                ans += f

        return ans