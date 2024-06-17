class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        
        for i in range(c + 1):
            j = c - (i ** 2)
            if j < 0:
                break
            sq_j = j ** 0.5
            if sq_j == int(sq_j):
                return True
        
        return False