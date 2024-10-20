class Solution:
    # Recursively parse and evaluate the boolean expression
    def _evaluate(self, expr: str, index: List[int]) -> bool:
        curr_ch = expr[index[0]]
        index[0] += 1
        
        # Base cases: true ('t') or false ('f')
        if curr_ch == 't':
            return True
        
        if curr_ch == 'f':
            return False
        
        # Handle Not operation '!(...)'
        if curr_ch == '!':
            index[0] += 1   # Skip '('
            res = not self._evaluate(expr, index)
            index[0] += 1   # Skip ')'
            return res
        
        # Handle AND '&(...)' and OR '|(...)'
        values = []
        index[0] += 1   # skip '('
        while expr[index[0]] != ')':
            if expr[index[0]] != ',':
                # Collect results of subexpressions
                values.append(self._evaluate(expr, index))
            else:
                index[0] += 1   # Skip commas
        index[0] += 1   # skip ')'
        
        # Manual AND operation: returns false if any value is false
        if curr_ch == '&':
            return all(values)
        
        # Manual OR operation: returns true if any value is true
        if curr_ch == '|':
            return any(values)
        
        return False        # This point should never be reached
    
    def parseBoolExpr(self, expression: str) -> bool:
        # Using a list because Python variables are passed by object reference
        index = [0]
        return self._evaluate(expression, index)