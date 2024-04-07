class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        # Pass 1: Remove all invalid ")"
        first_pass_chars = []
        balance, open_seen = 0, 0
        
        for c in s:
            if c == '(':
                balance += 1
                open_seen += 1
            
            if c == ')':
                if balance == 0:
                    continue
                balance -= 1
            first_pass_chars.append(c)
            
        # Pass 2: Remove the rightmost ')'
        result = []
        open_to_keep = open_seen - balance
        for c in first_pass_chars:
            if c == '(':
                open_to_keep -= 1
                if open_to_keep < 0:
                    continue
            result.append(c)
        
        return "".join(result)