class Solution:
    def countHomogenous(self, s: str) -> int:
        substr, ans = "", 0
        for c in s:
            if not substr or substr[-1] == c:
                substr += c
            else:
                substr = c
            ans = (ans + len(substr)) % (1_000_000_007)
            
        return ans