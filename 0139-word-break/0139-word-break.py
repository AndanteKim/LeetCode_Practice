class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        
        @lru_cache(maxsize = None)
        def dp(i: int) -> bool:
            if i < 0:
                return True
            
            for word in wordDict:
                if s[i - len(word) + 1: i + 1] == word and dp(i - len(word)):
                    return True
            
            return False
        n = len(s)
        return dp(n - 1)
        