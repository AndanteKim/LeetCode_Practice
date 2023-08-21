class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        substr, n = "", len(s)
        for i in range(n - 1):
            substr += s[i]
            if substr * (n // len(substr)) == s:
                return True
        
        return False