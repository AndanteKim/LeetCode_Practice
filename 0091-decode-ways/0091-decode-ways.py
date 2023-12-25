class Solution:
    def numDecodings(self, s: str) -> int:
        @lru_cache(maxsize = None)
        def dp(i: int) -> int:
            if i >= n or s[i] == '0':
                if i == n:
                    return 1
                return 0
            
            ways = 0
            ways += dp(i + 1)
            if i + 1 < n and s[i] + s[i + 1] in mapping:
                ways += dp(i + 2)
            
            return ways
        
        mapping = {
            "1":'A',"2":'B',"3":'C',"4":'D',"5":'E',"6":'F',"7":'G',"8":'H',"9":'I',
            "10":'J',"11":'K',"12":'L',"13":'M',"14":'N',"15":'O',"16":'P',"17":'Q',
            "18":'R',"19":'S',"20":'T',"21":'U',"22":'V',"23":'W',"24":'X',"25":'Y',
            "26":'Z'
        }
        
        n = len(s)
        return 0 if s[0] == '0' else dp(0)