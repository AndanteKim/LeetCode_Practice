class Solution:
    def maxDepthAfterSplit(self, seq: str) -> list[int]:
        n = len(seq)
        ans, cnt = [0] * n, 0

        for i, c in enumerate(seq):
            if c == '(':
                cnt += 1
                ans[i] = cnt % 2
            elif c == ')':
                ans[i] = cnt % 2
                cnt -= 1
            
        return ans