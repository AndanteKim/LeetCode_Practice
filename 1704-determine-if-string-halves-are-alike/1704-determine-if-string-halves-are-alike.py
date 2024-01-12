class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        
        def countVowel(start: int, end: int, s: str) -> int:
            ans = 0
            for i in range(start, end):
                if s[i] in "aieouAIEOU":
                    ans += 1
            
            return ans
        
        n = len(s)
        return countVowel(0, n // 2, s) == countVowel(n // 2, n, s)