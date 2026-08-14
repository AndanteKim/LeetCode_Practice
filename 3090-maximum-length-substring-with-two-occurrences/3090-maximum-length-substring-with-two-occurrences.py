class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        left, n = 0, len(s)
        ans, freq = 0, dict()

        for right in range(n):
            freq[s[right]] = freq.get(s[right], 0) + 1

            while left < right and freq[s[right]] > 2:
                freq[s[left]] -= 1
                left += 1

            ans = max(ans, right - left + 1)

        return ans