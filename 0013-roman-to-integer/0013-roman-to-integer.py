class Solution:
    def romanToInt(self, s: str) -> int:
        values = {
            "I": 1, "V": 5, "X": 10, "L": 50,\
            "C": 100, "D": 500, "M": 1000\
        }
        
        total, n = values[s[-1]], len(s) - 1
        
        for i in range(n - 1, -1, -1):
            if values[s[i]] < values[s[i + 1]]:
                total -= values[s[i]]
            else:
                total += values[s[i]]
        
        return total
    