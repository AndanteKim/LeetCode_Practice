class Solution:
    def makeFancyString(self, s: str) -> str:
        stack = []
        
        for c in s:
            stack.append(c)
            if len(stack) >= 3 and stack[-3] == stack[-2] == stack[-1]:
                stack.pop()
            
        return "".join(stack)