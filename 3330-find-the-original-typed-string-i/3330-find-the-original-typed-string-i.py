class Solution:
    def possibleStringCount(self, word: str) -> int:
        ans, stack = 0, []

        for c in word:
            if stack and stack[-1] == c:
                ans += 1

            stack.append(c)

        return ans + 1