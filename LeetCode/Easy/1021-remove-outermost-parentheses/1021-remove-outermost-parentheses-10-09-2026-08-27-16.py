class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        def recursive(i: int, cnt: int) -> str:
            if i == n:
                return ""
            
            ans = ""
            if s[i] == '(':
                if cnt == 0:
                    ans = recursive(i + 1, cnt + 1)
                else:
                    ans = '(' + recursive(i + 1, cnt + 1)
            else:
                if cnt == 1:
                    ans = recursive(i + 1, cnt - 1)
                else:
                    ans = ')' + recursive(i + 1, cnt - 1)
            return ans
        
        n = len(s)
        return recursive(0, 0)