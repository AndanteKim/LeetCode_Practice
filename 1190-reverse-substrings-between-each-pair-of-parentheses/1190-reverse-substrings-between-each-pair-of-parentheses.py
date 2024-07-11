class Solution:
    def reverseParentheses(self, s: str) -> str:
        stack, ans = [], []
        
        for c in s:
            if c == '(':
                # Store the current length as the start index
                # for future reversal
                stack.append(len(ans))
            elif c == ')':
                start = stack.pop()
                
                # Reverse the substring between the matching parenthesis
                ans[start:] = ans[start:][::-1]
                
            else:
                # Append non-parenthesis characters to the processed list
                ans.append(c)
                
        return "".join(ans)
        