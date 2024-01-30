class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack, ans = [], 0
        
        for token in tokens:
            if token in ('+', '-', '*', '/'):
                second, first = int(stack.pop()), int(stack.pop())
                ops = 0
                if token == '+':
                    ops += first + second
                elif token == '-':
                    ops += first - second
                elif token == '*':
                    ops += first * second
                else:
                    ops += first / second
                stack.append(ops)
                
            else:
                stack.append(token)
        
        ans = int(stack.pop())
        return ans