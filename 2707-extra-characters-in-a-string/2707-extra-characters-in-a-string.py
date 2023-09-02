class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        @lru_cache(maxsize = None)
        def dp(start: int) -> int:
            if start == n:
                return 0
            
            # To count this character as a left over character
            # move to index 'start + 1'
            ans = dp(start + 1) + 1
            for end in range(start, n):
                curr = s[start: end + 1]
                if curr in dict_set:
                    ans = min(ans, dp(end + 1))
            return ans
        
        n, dict_set = len(s), set(dictionary)
        return dp(0)
        
        