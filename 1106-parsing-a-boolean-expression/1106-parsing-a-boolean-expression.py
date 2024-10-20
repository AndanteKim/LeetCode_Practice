class Solution:
    # Evaluates a subexpression based on the operator and list of values
    def _eval_sub_expr(self, op: chr, values: List[chr]) -> chr:
        if op == '!':
            return 'f' if values[0] == 't' else 't'
        
        # AND: return 'f' if any value is 'f', otherwise return 't'
        if op == '&':
            for val in values:
                if val == 'f':
                    return 'f'
            return 't'
            
        # OR: return 't' if any value is 't', otherwise return 'f'
        if op == '|':
            for val in values:
                if val == 't':
                    return 't'
            return 'f'
            
        return 'f'      # This point should never be reached
    
    def parseBoolExpr(self, expression: str) -> bool:
        st = []
        
        # Traverse the entire expression
        for c in expression:
            if c == ')':
                values = []
                
                # Gather all values inside the parentheses
                while st[-1] != '(':
                    values.append(st.pop())
                st.pop()    # Remove '('
                op = st.pop()   # Remove the operator
                
                # Evaluate the subexpression and push the result back
                res = self._eval_sub_expr(op, values)
                st.append(res)
            elif c != ',':
                st.append(c)    # Push non-comma characters into the stack
                
        # Final result is on the top of the stack
        return st[-1] == 't'