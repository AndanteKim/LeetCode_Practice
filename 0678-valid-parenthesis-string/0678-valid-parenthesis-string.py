class Solution:
    def checkValidString(self, s: str) -> bool:
        n = len(s)
        # dp[i][j] represents if the substring starting from index i is valid with j opening brackets
        dp = [[False] * (n + 1) for _ in range(n + 1)]
        
        # base case: an empty string with 0 opening brackets is valid
        dp[n][0] = True
        
        for index in range(n - 1, -1, -1):
            for open_bracket in range(n):
                is_valid = False
                
                # '*' can represent '(' or ')' or '' (empty)
                if s[index] == '*':
                    if open_bracket < n:
                        is_valid |= dp[index + 1][open_bracket + 1] # try '*' as '('
                    
                    # opening brackets to use '*' as ')'
                    if open_bracket > 0:
                        is_valid |= dp[index + 1][open_bracket - 1] # try '*' as ')'
                    is_valid |= dp[index + 1][open_bracket] # ignore '*'
                else:
                    # If the character is not '*', it can be '(' or ')'
                    if s[index] == '(':
                        is_valid |= dp[index + 1][open_bracket + 1] # try '('
                    elif open_bracket > 0:
                        is_valid |= dp[index + 1][open_bracket - 1] # try ')'
                
                dp[index][open_bracket] = is_valid
        
        return dp[0][0] # check if the entire string is valid with no excess opening brackets