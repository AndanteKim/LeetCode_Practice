class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        # Initialize memoization dictionary to store results of subproblems
        memo = dict()
        
        # Solve for the entire expression
        return self._compute_res(expression, memo, 0, len(expression) - 1)
    
    def _compute_res(self, expression: str, memo: Dict[str, int], start: int, end: int) -> List[int]:
        # If result is already memoized, return it
        if (start, end) in memo:
            return memo[(start, end)]
        
        ans, operations = [], {'+': lambda x, y : x + y, '-': lambda x, y: x - y, \
                              '*': lambda x, y: x * y}
        
        # Base case: single digit
        if start == end:
            return [int(expression[start])]
        
        # Base case: two-digit number
        if end - start == 1 and expression[start].isdigit():
            return [int(expression[start : end + 1])]
        
        
        # Recursive case: split the expression at each operator
        for i in range(start, end + 1):
            if expression[i].isdigit():
                continue
                
            left_res = self._compute_res(expression, memo, start, i - 1)
            right_res = self._compute_res(expression, memo, i + 1, end)
            
            # Combine results from left and right subexpressions
            for left_val in left_res:
                for right_val in right_res:
                    ans.append(operations[expression[i]](left_val, right_val))
                    
        # Memoize the result for this subproblem
        memo[(start, end)] = ans
        
        return ans