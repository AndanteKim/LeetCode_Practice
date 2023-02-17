class Solution:
    def makeGood(self, s: str) -> str:
        stack = []
        for c in s:
            if stack:
                if stack[-1] == c:
                    stack.append(c)
                elif ord(stack[-1]) == ord(c) - 32 or ord(stack[-1]) == ord(c) + 32:
                    stack.pop()
                else:
                    stack.append(c)
            else:
                stack.append(c)
        return "".join(stack)