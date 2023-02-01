class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        chars_list, left = defaultdict(int), 0
        ans = 0
        for right in range(len(s)):
            if chars_list[s[right]] == 0:
                chars_list[s[right]] += 1
            else:
                while chars_list[s[right]] > 0:
                    chars_list[s[left]] -= 1
                    left += 1
                chars_list[s[right]] += 1
            
            ans = max(ans, right - left + 1)
        return ans
                    