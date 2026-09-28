class Solution:
    def maxDepth(self, s: str) -> int:
        ans, cnt = 0, 0

        for c in s:
            if c == '(':
                cnt += 1
            elif c == ')':
                cnt -= 1
            ans = max(ans, cnt)
        
        return ans