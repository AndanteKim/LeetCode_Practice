class Solution:
    def maxFreqSum(self, s: str) -> int:
        vowels_f, consonants_f = dict(), dict()
        vowels = "aeiou"

        for c in s:
            if c in vowels:
                vowels_f[c] = vowels_f.get(c, 0) + 1
            else:
                consonants_f[c] = consonants_f.get(c, 0) + 1
        
        return (max(vowels_f.values()) if len(vowels_f) > 0 else 0) + (max(consonants_f.values()) if len(consonants_f) > 0 else 0)