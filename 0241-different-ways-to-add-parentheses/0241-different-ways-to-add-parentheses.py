class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        n = len(expression)
        
        # Create a 2D array of lists to store results of subproblems
        dp = [[[] for _ in range(n)] for _ in range(n)]
        
        self._init_base_cases(expression, dp)
        
        # Fill the dp table for all possible subexpressions
        for length in range(3, n + 1):
            for start in range(n - length + 1):
                end = start + length - 1
                self._process_subexpression(expression, dp, start, end)
                
        # Return the results for the entire expression
        return dp[0][n - 1]
    
    def _init_base_cases(self, expression: str, dp: List[List[List[int]]]) -> None:
        # Handle base cases: single digits and two-digit numbers
        for i, ch in enumerate(expression):
            if ch.isdigit():
                # Check if it's a two-digit number
                d1 = ord(ch) - 48
                if i + 1 < len(expression) and expression[i + 1].isdigit():
                    d2 = ord(expression[i + 1]) - 48
                    num = d1 * 10 + d2
                    dp[i][i + 1].append(num)
                # Single digit case
                dp[i][i].append(d1)
                
    def _process_subexpression(self, expression: str, dp: List[List[List[int]]], start: int, end: int) -> None:
        operations = {'+': lambda x, y: x + y, '-': lambda x, y: x - y, '*': lambda x, y: x * y}
        
        # Try all possible positions to split the expression
        for split in range(start, end + 1):
            if expression[split].isdigit():
                continue
                
            left_res = dp[start][split - 1]
            right_res = dp[split + 1][end]
            
            # Compute the results based on the operator at position 'split'
            for left_val in left_res:
                for right_val in right_res:
                    dp[start][end].append(operations[expression[split]](left_val, right_val))
    