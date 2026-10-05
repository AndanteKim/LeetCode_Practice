class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        ans = cnt = 0

        for i, c in enumerate(s):
            if c == '(':
                cnt += 1
            else:
                cnt -= 1

                if i > 0 and s[i - 1] == '(':
                    ans += 1 << cnt

        return ans