class Solution:
    def checkValidString(self, s: str) -> bool:
        open_cnt, close_cnt = 0, 0
        length = len(s) - 1

        for i in range(length + 1):
            if s[i] == '(' or s[i] == '*':
                open_cnt += 1
            else:
                open_cnt -= 1
            
            if s[length - i] == ')' or s[length - i] == '*':
                close_cnt += 1
            else:
                close_cnt -= 1
            
            if open_cnt < 0 or close_cnt < 0:
                return False
        
        return True