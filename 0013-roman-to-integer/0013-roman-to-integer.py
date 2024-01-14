class Solution:
    def romanToInt(self, s: str) -> int:
        values = {
            'I':1,'V':5,'X':10,\
            'L':50,'C':100,'D':500,\
            'M':1000
        }
        
        total, i = 0, 0
        while i < len(s):
            # If this is the subractive case.
            if i + 1 < len(s) and values[s[i]] < values[s[i + 1]]:
                total += values[s[i + 1]] - values[s[i]]
                i += 2
                
            # Else this is NOT the subractive case.
            else:
                total += values[s[i]]
                i += 1
        
        return total
        