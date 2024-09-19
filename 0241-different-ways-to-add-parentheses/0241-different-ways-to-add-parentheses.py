class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        # Base case: If the string is empty, return an empty list
        if not expression:
            return []
        
        ans, n, operations = [], len(expression), {
            '+': lambda x, y: x + y,
            '-': lambda x, y: x - y,
            '*': lambda x, y: x * y
        }
        
        # Base case: If the string is a single character or two characters\
        # and the first character is a digit, parse it as a number and return it.
        if n == 1 or (n == 2 and expression[0].isdigit()):
            return [int(expression)]
        
        # Recursive case: Iterate through each character.
        for i, curr in enumerate(expression):
            # Skip if the current character is a digit.
            if curr.isdigit():
                continue
            
            # Split the expression into left and right parts
            left_res = self.diffWaysToCompute(expression[:i])
            right_res = self.diffWaysToCompute(expression[i + 1:])
            
            # Combine results from left and right parts
            for left_val in left_res:
                for right_val in right_res:
                    # Perform the operation based on the current character
                    ans.append(operations[curr](left_val, right_val))
        
        return ans