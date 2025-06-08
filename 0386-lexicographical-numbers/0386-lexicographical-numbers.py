class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        def backtrack(curr: int) -> None:
            if curr > n:
                return

            ans.append(curr)
            for i in range(0, 10):
                backtrack(curr * 10 + i)

        ans = []
        for i in range(1,10):
            backtrack(i)

        return ans