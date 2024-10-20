class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        # Repeatedly simplify the expression by evaluating subexpressions
        while len(expression) > 1:
            start = max(expression.rfind("!"), expression.rfind("&"), expression.rfind("|"))
            end = expression.find(")", start)
            sub_expr = expression[start : end + 1]
            res = self._evaluate_sub_expr(sub_expr)
            expression = expression[:start] + res + expression[end + 1 :]
            
        return expression == "t"
    
    def _evaluate_sub_expr(self, sub_expr: str) -> str:
        # Extract the operator and the enclosed values
        op, values = sub_expr[0], sub_expr[2:-1]
        
        # Apply logical operations based on the operator
        if op == "!":
            return "f" if values == "t" else "t"
        if op == "&":
            return "f" if "f" in values else "t"
        if op == "|":
            return "t" if "t" in values else "f"
        
        # This point should never be reached
        return "f"