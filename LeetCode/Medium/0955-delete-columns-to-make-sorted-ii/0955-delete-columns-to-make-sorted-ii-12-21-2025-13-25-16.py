class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        ans, n, k = 0, len(strs), len(strs[0])
        curr, col_words = [""] * n, [""] * k

        for r in range(n):
            for c in range(k):
                col_words[c] += strs[r][c]

        for col in col_words:
            curr2 = curr[:]
            for i, c in enumerate(col):
                curr2[i] += c
            
            is_sorted = True
            for i in range(1, n):
                if curr2[i - 1] > curr2[i]:
                    is_sorted = False
                    break
                
            if is_sorted:
                curr = curr2
            else:
                ans += 1

        return ans