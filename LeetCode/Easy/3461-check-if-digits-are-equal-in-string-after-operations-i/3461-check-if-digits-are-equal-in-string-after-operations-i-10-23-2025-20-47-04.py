class Solution:
    def hasSameDigits(self, s: str) -> bool:
        n, new_s = len(s), s

        while n > 2:
            reduced = ""
            for i in range(n - 1):
                reduced += chr((int(new_s[i]) + int(new_s[i + 1])) % 10 + 48)
            
            n = len(reduced)
            new_s = reduced
        
        return new_s[0] == new_s[1]