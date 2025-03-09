class Solution:
    def numKLenSubstrNoRepeats(self, s: str, k: int) -> int:
        if len(s) < k:
            return 0

        ans, chars, n = 0, defaultdict(int), len(s)
        left = 0

        for right in range(n):
            chars[s[right]] += 1
 
            while left < right and chars[s[right]] >= 2:
                chars[s[left]] -= 1
                left += 1
            
            if right - left + 1 >= k:
                ans += 1

        return ans