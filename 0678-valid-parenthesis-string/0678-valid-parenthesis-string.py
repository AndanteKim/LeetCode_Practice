class Solution:
    def checkValidString(self, s: str) -> bool:
        open_bracket, asterisk = [], []
        
        for i in range(len(s)):
            if s[i] == '(':
                open_bracket.append(i)
                
            elif s[i] == ')':
                if not (open_bracket or asterisk):
                    return False
                if open_bracket:
                    open_bracket.pop()
                else:
                    asterisk.pop()
                
            else:
                asterisk.append(i)
            
        while open_bracket and asterisk:
            # If the order of asterisk shows before the open bracket
            if open_bracket.pop() > asterisk.pop():
                return False
           
        return False if open_bracket else True