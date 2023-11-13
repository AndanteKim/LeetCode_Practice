class Solution:
    def sortVowels(self, s: str) -> str:
        def is_vowel(ch: chr) -> bool:
            return ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U' or\
        ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u'
        
        count = defaultdict(int)
        for c in s:
            if is_vowel(c):
                count[c] += 1
        
        sorted_vowel = "AEIOUaeiou"
        ans, j = "", 0
        
        for i in range(len(s)):
            if is_vowel(s[i]):
                while count[sorted_vowel[j]] == 0:
                    j += 1
                ans += sorted_vowel[j]
                count[sorted_vowel[j]] -= 1
        
            else:
                ans += s[i]
        
        return ans