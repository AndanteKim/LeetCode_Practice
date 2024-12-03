class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        ans, start = "", 0
        
        for spc in spaces:
            ans += s[start : spc] + " "
            start = spc
        last_word = s[start:]
        ans = ans[:-1] if len(last_word) == 0 else ans + last_word
            
        return ans