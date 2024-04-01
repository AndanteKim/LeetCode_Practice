class Solution:
    def lengthOfLongestSubstringTwoDistinct(self, s: str) -> int:
        freq, ans, left = defaultdict(int), 0, 0
        
        for right in range(len(s)):
            freq[s[right]] += 1
            
            while len(freq) > 2 and left < right:
                freq[s[left]] -= 1
                if freq[s[left]] == 0:
                    del freq[s[left]]
                left += 1
                
            ans = max(ans, right - left + 1)
        
        return ans