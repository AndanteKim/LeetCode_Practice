class Solution:
    def hasSameDigits(self, s: str) -> bool:
        n, new_s = len(s), ""

        while n > 2:
            new_s = ""
            for i in range(n - 1):
                new_s += chr((int(s[i]) + int(s[i + 1])) % 10 + 48)
            
            n = len(new_s)
            s = new_s
        
        return new_s[0] == new_s[1]