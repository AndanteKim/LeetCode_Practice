class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        operations = {
            "+": lambda a, b: a + b,
            "-": lambda a, b: a - b,
            "*": lambda a, b: a * b,
            "/": lambda a, b: int(a / b)
        }
        
        curr_pos = 0
        
        while len(tokens) > 1:
            # Move the current position pointer to the next operator
            while tokens[curr_pos] not in "+-*/":
                curr_pos += 1
            
            # Extract the operator and numbers from the list
            operator = tokens[curr_pos]
            n1, n2 = int(tokens[curr_pos - 2]), int(tokens[curr_pos - 1])
            
            # Calculate the result to overwrite the operator with
            operation = operations[operator]
            tokens[curr_pos] = operation(n1, n2)
            
            # Remove the numbers and move the pointer to the position
            # after the new number we just added.
            tokens.pop(curr_pos - 2)
            tokens.pop(curr_pos - 2)
            curr_pos -= 1
            
        return int(tokens[0])