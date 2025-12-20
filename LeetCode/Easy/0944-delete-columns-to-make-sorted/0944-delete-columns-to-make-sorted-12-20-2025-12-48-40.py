class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        rows, cols = len(strs), len(strs[0]) 
        col_words = [""] * cols

        for r in range(rows):
            for c in range(cols):
                col_words[c] += strs[r][c]

        ans = 0
        for c in range(cols):
            for i in range(len(col_words[c]) - 1):
                if col_words[c][i] > col_words[c][i + 1]:
                    ans += 1
                    break

        return ans