class Solution:
    def checkValidString(self, s: str) -> bool:
        open_count, close_count = 0, 0
        n = len(s) - 1
        
        # Traverse the string from both ends simultaneously
        for i in range(n + 1):
            # Count open parentheses or asterisks
            if s[i] == '(' or s[i] == '*':
                open_count += 1
            else:
                open_count -= 1
           
            # Count close parentheses or asterisks
            if s[n - i] == ')' or s[n - i] == '*':
                close_count += 1
            else:
                close_count -= 1
            
            # If at any point open count or close count goes negative, the string is invalid
            if open_count < 0 or close_count < 0:
                return False
            
        # If open count and close count are both non-negative, the string is valid.
        return True
        