class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        chars, ans = set(word), 0

        for ch in chars:
            if chr(ord(ch) + 32) in chars or chr(ord(ch) - 32) in chars:
                ans += 1

        return ans >> 1