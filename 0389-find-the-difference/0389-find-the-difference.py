class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        ch = 0
        
        for char_ in s:
            ch ^= ord(char_)
        
        for char_ in t:
            ch ^= ord(char_)
        
        return chr(ch)