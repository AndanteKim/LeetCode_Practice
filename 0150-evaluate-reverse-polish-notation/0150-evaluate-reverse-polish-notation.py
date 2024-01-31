class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        operations = {
            "+": lambda a, b: a + b,
            "-": lambda a, b: a - b,
            "*": lambda a, b: a * b,
            "/": lambda a, b: int(a / b)
        }
        
        stack = []
        for token in tokens:
            if token in operations:
                n2 = stack.pop()
                n1 = stack.pop()
                opr = operations[token]
                stack.append(opr(n1, n2))
            else:
                stack.append(int(token))
        
        return stack.pop()