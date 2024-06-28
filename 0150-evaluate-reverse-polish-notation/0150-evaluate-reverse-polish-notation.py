class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        ops = {
            "+": lambda x, y: x + y,
            "-": lambda x, y: x - y,
            "*": lambda x, y: x * y,
            "/": lambda x, y: int(x / y)
        }
        
        ans, stack, first, second = 0, [], None, None
        
        for token in tokens:
            if token in {"+", "-", "*", "/"}:
                second = stack.pop()
                first = stack.pop()
                stack.append(ops[token](first, second))
               
            else:
                stack.append(int(token))
                
        return stack[-1]