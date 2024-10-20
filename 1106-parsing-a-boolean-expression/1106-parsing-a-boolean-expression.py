class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        st = []
        
        # Traverse through the expression
        for c in expression:
            if c == ',' or c == '(':
                continue    # Skip commas and open parentheses
                
            # Push operators and boolean values to the stack
            if c in "tf!&|":
                st.append(c)
                
            # Handle closing parentheses and evaluate the subexpression
            if c == ')':
                has_true, has_false = False, False
                
                # Process the values inside the parenthesis
                while st[-1] not in '!&|':
                    val = st.pop()
                    if val == 't':
                        has_true = True
                    
                    if val == 'f':
                        has_false = True
                
                # Pop the operator and evaluate the subexpression
                op = st.pop()
                if op == '!':
                    st.append('t' if not has_true else 'f')
                
                elif op == '&':
                    st.append('f' if has_false else 't')
                else:
                    st.append('t' if has_true else 'f')
        
        # The final result is at the top of the stack
        return st[-1] == 't'
        