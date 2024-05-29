class Solution:
    def add_one(self, s: List[str]) -> None:
        i = len(s) - 1
        
        # Iterating while the character is 1 and changing to 0
        while i >= 0 and s[i] != '0':
            s[i] = '0'
            i -= 1
        
        if i < 0:
            s.insert(0, "1")
        else:
            s[i] = "1"
    
    def numSteps(self, s: str) -> int:
        s = list(s)
        operations = 0
        
        while len(s) > 1:
            n = len(s)
            
            if s[n - 1] == '0':
                s.pop()
            else:
                self.add_one(s)
        
            operations += 1
        
        return operations