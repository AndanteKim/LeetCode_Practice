class Solution:
    def numSteps(self, s: str) -> int:
        n, num = len(s), 0
        
        for i in range(n):
            num += (ord(s[i]) - 48) * (2 ** (n - 1 - i))
            
        steps = 0
        while num > 1:
            # If num is even
            if num % 2 == 0:
                num >>= 1
                
            else:
                num += 1
            steps += 1
        
        return steps