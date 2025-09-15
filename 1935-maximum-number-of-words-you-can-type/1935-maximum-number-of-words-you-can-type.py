class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        unavailable, words = set(brokenLetters), [word for word in text.split()]

        ans = 0
        for word in words:
            available = True
            for c in word:
                if c in unavailable:
                    available = False
                    break
            if available:
                ans += 1
        
        return ans