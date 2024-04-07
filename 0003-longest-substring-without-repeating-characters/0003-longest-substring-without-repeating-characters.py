class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        chars, left, ans = defaultdict(int), 0, 0
        
        for right in range(len(s)):
            chars[s[right]] += 1
            
            while chars[s[right]] > 1 and left <= right:
                chars[s[left]] -= 1
                left += 1
                
            ans = max(ans, right - left + 1)
        
        return ans