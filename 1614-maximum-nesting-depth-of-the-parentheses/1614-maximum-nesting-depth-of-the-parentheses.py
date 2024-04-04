class Solution:
    def maxDepth(self, s: str) -> int:
        stack, ans, curr = [], 0, 0
        
        for c in s:
            if c == '(':
                stack.append('(')
                curr += 1
            elif c == ')':
                stack.pop()
                ans = max(ans, curr)
                curr -= 1
        
        return ans if not stack else 0