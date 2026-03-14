class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        def backtrack(remain: int, curr: str) -> None:
            if remain == 0:
                if curr not in candidates:
                    candidates.append(curr)
                return
            
            for ch in ['a', 'b', 'c']:
                if len(curr) == 0 or ch != curr[-1]:
                    backtrack(remain - 1, curr + ch)

        candidates = []
        backtrack(n, "")


        return "" if len(candidates) < k else candidates[k - 1]