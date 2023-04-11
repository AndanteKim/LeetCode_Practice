class Solution:
    def removeStars(self, s: str) -> str:
        stack = []
        for c in s:
            if c != '*':
                stack.append(c)
            elif stack:
                stack.pop()
        
        return "".join(stack)
                