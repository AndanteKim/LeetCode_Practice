class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        stack_s, stack_t = [], []
        
        for c in s:
            if c == '#':
                if stack_s:
                    stack_s.pop()
            else:
                stack_s.append(c)
        
        for c in t:
            if c == '#':
                if stack_t:
                    stack_t.pop()
            else:
                stack_t.append(c)
        
        return "".join(stack_s) == "".join(stack_t)