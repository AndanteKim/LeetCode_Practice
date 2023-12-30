class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        chars, n = [0] * 26, len(words)
        
        for word in words:
            for c in word:
                chars[ord(c) - 97] += 1
        
        for i in range(26):
            if chars[i] % n != 0:
                return False
        
        return True