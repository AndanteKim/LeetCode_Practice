class Solution:
    def _find_gcd(self, a: int, b: int) -> int:
        if a == 0:
            return b
        
        return self._find_gcd(b % a, a)
    
    def fractionAddition(self, expression: str) -> str:
        num, denom = 0, 1
        
        i, n = 0, len(expression)
        while i < n:
            curr_num, curr_denom = 0, 0
            is_negative = False
            
            # Check for sign
            if expression[i] == '-' or expression[i] == '+':
                if expression[i] == '-':
                    is_negative = True
                # Move to next character
                i += 1
                
            # Build numerator
            while i < n and expression[i].isdigit():
                val = int(expression[i])
                curr_num = curr_num * 10 + val
                i += 1
                
            if is_negative:
                curr_num *= -1
                
            # Skip divisor
            i += 1
            
            # Build denominator
            while i < n and expression[i].isdigit():
                val = int(expression[i])
                curr_denom = curr_denom * 10 + val
                i += 1
                
            # Add fractions together using common denominator
            num = num * curr_denom + curr_num * denom
            denom = denom * curr_denom
            
        gcd = abs(self._find_gcd(num, denom))
        
        # Reduce fractions
        num //= gcd
        denom //= gcd
        
        return f"{num}/{denom}"