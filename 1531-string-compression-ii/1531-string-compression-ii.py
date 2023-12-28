class Solution:
    def getLengthOfOptimalCompression(self, s: str, k: int) -> int:
        @lru_cache(maxsize = None)
        def dp(i: int, last_char: chr, last_char_count: int, remain: int) -> int:
            if remain < 0:
                return float('inf')
            
            if i == n:
                return 0
            
            delete_char = dp(i + 1, last_char, last_char_count, remain - 1)
            if s[i] == last_char:
                keep_char = dp(i + 1, last_char, last_char_count + 1, remain) + (last_char_count in [1, 9, 99])
            else:
                keep_char = dp(i + 1, s[i], 1, remain) + 1
            
            return min(keep_char, delete_char)
        
        n = len(s)
        return dp(0, '', 0, k)