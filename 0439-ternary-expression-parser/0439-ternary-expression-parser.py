class Solution:
    def isValidAtomic(self, s: str) -> bool:
        return s[0] in 'TF' and s[1] == '?' and s[2] in 'TF0123456789'\
    and s[3] == ':' and s[4] in 'TF0123456789'
    
    def solveAtomic(self, s: str) -> str:
        return s[2] if s[0] == 'T' else s[4]
    
    def parseTernary(self, expression: str) -> str:
        while len(expression) != 1:
            j = len(expression) - 1
            while not self.isValidAtomic(expression[j - 4 : j + 1]):
                j -= 1
            expression = expression[:j - 4] +\
            self.solveAtomic(expression[j - 4: j + 1]) + expression[j + 1:]
            
        return expression