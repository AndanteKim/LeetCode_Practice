class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        mismatch, stack = 0, []
        
        for c in s:
            if c == '(':
                stack.append(c)
                continue
            else:
                if stack:
                    stack.pop()
                else:
                    mismatch += 1
        
        while stack:
            stack.pop()
            mismatch += 1

        return mismatch