class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        left, max_vowel = 0, 0
        
        vowel = ('a','e','i','o','u')
        for c in s[left:k]:
            if c in vowel:
                max_vowel += 1
        curr = max_vowel
        for right in range(k, len(s)):
            if s[right] in vowel:
                curr += 1
            if s[left] in vowel:
                curr -= 1
            left += 1
            max_vowel = max(max_vowel, curr)
            
        return max_vowel