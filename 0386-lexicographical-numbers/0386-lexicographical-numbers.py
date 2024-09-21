class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        def backtrack(digit: int) -> None:
            if digit > n:
                return
                
            ans.append(digit)
            digit *= 10
            for i in range(0, 10):
                backtrack(digit + i)
        
        ans = []
        for i in range(1, 10):
            backtrack(i)
        return ans