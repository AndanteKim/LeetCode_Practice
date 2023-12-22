class Solution:
    def lengthOfLongestSubstringTwoDistinct(self, s: str) -> int:
        small_chars, capital_chars = [0] * 26, [0] * 26
        two_chars, n = set(), len(s)
        left, ans = 0, 0
        
        for right in range(n):
            if s[right] not in two_chars:
                while len(two_chars) >= 2 and left < right:
                    if 0 <= ord(s[left]) - 65 < 26:
                        capital_chars[ord(s[left]) - 65] -= 1
                        if capital_chars[ord(s[left]) - 65] == 0:
                            two_chars.remove(s[left])
                    else:
                        small_chars[ord(s[left]) - 97] -= 1
                        if small_chars[ord(s[left]) - 97] == 0:
                            two_chars.remove(s[left])
                    left += 1
                two_chars.add(s[right])
            
            if 0 <= ord(s[right]) - 65 < 26:
                capital_chars[ord(s[right]) - 65] += 1
            else:
                small_chars[ord(s[right]) - 97] += 1
            
            longest = 0
            for i in range(26):
                longest += small_chars[i]
                longest += capital_chars[i]
            ans = max(ans, longest)
        
        return ans