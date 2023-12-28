class Solution:
    def romanToInt(self, s: str) -> int:
        mapping = {
            "I":1, "II":2, "III":3, "IV":4, "V":5,
            "VI":6, "VII":7, "VIII":8, "IX":9, "X":10,
            "XL":40, "L":50, "XC":90, "C":100, "CD":400,
            "D":500, "CM":900, "M":1000 
        }
        
        i, n = 0, len(s)
        ans, curr = 0, ""
        while i < n:
            if curr + s[i] in mapping:
                curr += s[i]
            else:
                ans += mapping[curr]
                curr = s[i]
            i += 1
        
        if curr:
            ans += mapping[curr]
        return ans