# The knows API is already defined for you.
# return a bool, whether a knows b
# def knows(a: int, b: int) -> bool:

class Solution:
    def findCelebrity(self, n: int) -> int:
        self.n = n
        
        for i in range(n):
            if self.is_celebrity(i):
                return i
            
        return -1
    
    def is_celebrity(self, i: int):
        for j in range(self.n):
            if i == j:
                continue
                
            if knows(i, j) or not knows(j, i):
                return False
            
        return True