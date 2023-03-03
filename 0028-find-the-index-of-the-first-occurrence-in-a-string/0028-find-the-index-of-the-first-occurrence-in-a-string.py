class Solution:
    RADIX, MOD, MAX_WEIGHT = 26, 1_000_000_033, 1
    
    def hash_value(self, m: int, string: str) -> int:
        ans, factor = 0, 1
        
        for i in range(m - 1, -1, -1):
            ans += ((ord(string[i]) - 97) * (factor)) % self.MOD
            factor = (factor * self.RADIX) % self.MOD
        
        return ans % self.MOD
    
    def strStr(self, haystack: str, needle: str) -> int:
        m, n = len(needle), len(haystack)
        if n < m:
            return -1
            
        for _ in range(m):
            self.MAX_WEIGHT = (self.MAX_WEIGHT * self.RADIX) % self.MOD
        
        hash_needle = self.hash_value(m, needle)
        
        for window_start in range(n - m + 1):
            if window_start == 0:
                hash_hay = self.hash_value(m, haystack)
            else:
                hash_hay = ((hash_hay * self.RADIX) % self.MOD\
                            - ((ord(haystack[window_start - 1]) - 97)
                            * self.MAX_WEIGHT) % self.MOD
                            + (ord(haystack[window_start + m - 1]) - 97)
                            + self.MOD) % self.MOD
            
            if hash_needle == hash_hay:
                for i in range(m):
                    if needle[i] != haystack[i + window_start]:
                        break
                
                if i == m - 1:
                    return window_start
        
        return -1