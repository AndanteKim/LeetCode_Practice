class Solution:
    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
        ans, chars, left, n, curr = 0, dict(), 0, len(s), 0
        
        for right in range(n):
            add = s[right]
            if add not in chars:
                curr += 1
            chars[add] = chars.get(add, 0) + 1
            
            while len(chars) > k:
                chars[s[left]] -= 1
                if chars[s[left]] == 0:
                    del chars[s[left]]
                
                left += 1
                    
            ans = max(ans, right - left + 1)
        return ans
            