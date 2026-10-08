class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        ans, level = [], 0

        for c in s:
            if c == ')':
                level -= 1
            
            if level:
                ans.append(c)
            
            if c == '(':
                level += 1
        
        return "".join(ans)