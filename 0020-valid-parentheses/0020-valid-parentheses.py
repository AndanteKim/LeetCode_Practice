class Solution:
    def isValid(self, s: str) -> bool:
        stack, matching = [], {'}':'{', ')':'(', ']':'['}
        
        for c in s:
            if c in '{([':
                stack.append(c)
            elif stack and matching[c] == stack[-1]:
                stack.pop()
            else:
                return False
        return False if stack else True