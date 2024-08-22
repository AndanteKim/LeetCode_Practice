class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def backtrack(i: int, curr: str, balance: int) -> None:
            if i == n * 2:
                if balance == 0:
                    ans.append(curr)
                return
            
            if balance < 0:
                return
            
            backtrack(i + 1, curr + '(', balance + 1)
            backtrack(i + 1, curr + ')', balance - 1)
        
        ans = []
        backtrack(0, "", 0)
        
        return ans