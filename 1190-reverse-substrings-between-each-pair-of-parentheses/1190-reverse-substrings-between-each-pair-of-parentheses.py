class Solution:
    def reverseParentheses(self, s: str) -> str:
        stack = []
        
        for c in s:
            if c == ')':
                curr = ""
                while stack and stack[-1] != '(':
                    curr += stack.pop()
                
                if stack and stack[-1] == '(':
                    stack.pop()
                stack.append(curr[::-1])
            else:
                stack.append(c)
            
        ans = ""
        while stack:
            ans += stack.pop()
        
        return ans[::-1]