class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        def backtrack(i: int, curr: str):
            if i == n:
                words.append(curr)
                return

            for ch in ('a', 'b', 'c'):
                if curr == "" or ch != curr[-1]:
                    backtrack(i + 1, curr + ch)
        
        words = []
        backtrack(0, "")
        return "" if k > len(words) else words[k - 1]