class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        i, m, n = 0, len(haystack), len(needle)
        
        while i <= m - n:
            if haystack[i:i+n] == needle:
                return i
            i += 1
        
        return -1