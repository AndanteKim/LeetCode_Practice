class Solution:
    def isValid(self, s: str) -> bool:
        stack, symbol = [], {'}':'{', ')':'(', ']' : '['}
        
        for c in s:
            if c in ('(', '[', '{'):
                stack.append(c)
            elif stack and symbol[c] == stack[-1]:
                stack.pop()
            else:
                return False
                
        return True if not stack else False