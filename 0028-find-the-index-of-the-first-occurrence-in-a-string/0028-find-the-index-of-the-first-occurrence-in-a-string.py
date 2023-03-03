class Solution:
    RADIX_1, MOD_1 = 26, 10 ** 9 + 33
    RADIX_2, MOD_2 = 27, 2 ** 31 - 1
    MAX_WEIGHT_1, MAX_WEIGHT_2 = 1, 1
    
    def hash_pair(self, m: int, string: str) -> List[int]:
        hash_1 = hash_2 = 0
        factor_1 = factor_2 = 1
        
        for i in range(m - 1, -1, -1):
            hash_1 += ((ord(string[i]) - 97) * (factor_1)) % self.MOD_1
            factor_1 = (factor_1 * self.RADIX_1) % self.MOD_1
            hash_2 += ((ord(string[i]) - 97) * (factor_2)) % self.MOD_2
            factor_2 = (factor_2 * self.RADIX_2) % self.MOD_2
        
        return [hash_1 % self.MOD_1, hash_2 % self.MOD_2]
    
    def strStr(self, haystack: str, needle: str) -> int:
        m, n = len(needle), len(haystack)
        
        if n < m: return -1
        
        for _ in range(m):
            self.MAX_WEIGHT_1 = (self.MAX_WEIGHT_1 * self.RADIX_1) % self.MOD_1
            self.MAX_WEIGHT_2 = (self.MAX_WEIGHT_2 * self.RADIX_2) % self.MOD_2
        
        hash_needle = self.hash_pair(m, needle)
        
        for window_start in range(n - m + 1):
            if window_start == 0:
                hash_hay = self.hash_pair(m, haystack)
            else:
                hash_hay[0] = (((hash_hay[0] * self.RADIX_1) % self.MOD_1
                               - ((ord(haystack[window_start - 1]) - 97)
                                 * (self.MAX_WEIGHT_1)) % self.MOD_1
                               + (ord(haystack[window_start + m - 1]) - 97))
                               % self.MOD_1)
                hash_hay[1] = (((hash_hay[1] * self.RADIX_2) % self.MOD_2
                               - ((ord(haystack[window_start - 1]) - 97)
                                 * (self.MAX_WEIGHT_2)) % self.MOD_2
                               + (ord(haystack[window_start + m - 1]) - 97))
                               % self.MOD_2)
            
            if hash_needle == hash_hay:
                return window_start
        return -1