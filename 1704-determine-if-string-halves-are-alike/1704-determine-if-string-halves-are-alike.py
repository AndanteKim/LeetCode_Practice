class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        n, a_vowel_count = len(s), 0
        
        for i in range(n // 2):
            if s[i] in "aeiouAEIOU":
                a_vowel_count += 1
                
        b_vowel_count = 0
        for i in range(n // 2, n):
            if s[i] in "aeiouAEIOU":
                b_vowel_count += 1
        
        return a_vowel_count == b_vowel_count