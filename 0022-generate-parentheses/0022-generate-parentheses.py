class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        def backtrack(i: int, cnt: int, curr: str) -> None:
            if i == n:
                while cnt > 0:
                    curr += ')'
                    cnt -= 1
                ans.append(curr)
                return
            
            if cnt < 0:
                return

            backtrack(i + 1, cnt + 1, curr + '(')
            backtrack(i, cnt - 1, curr + ')')

        
        ans = []
        backtrack(0, 0, '')

        return ans