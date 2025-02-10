class Solution:
    def clearDigits(self, s: str) -> str:
        stack = []

        for c in s:
            if 48 <= ord(c) <= 57:
                if stack:
                    stack.pop()

            else:
                stack.append(c)

        return "".join(stack)