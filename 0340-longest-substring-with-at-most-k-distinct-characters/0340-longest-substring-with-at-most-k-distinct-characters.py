class Solution:
    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
        ans = 0
        counter = Counter()
        
        for right in range(len(s)):
            counter[s[right]] += 1
            
            if len(counter) <= k:
                ans += 1
            else:
                counter[s[right - ans]] -= 1
                if counter[s[right - ans]] == 0:
                    del counter[s[right - ans]]
        
        return ans