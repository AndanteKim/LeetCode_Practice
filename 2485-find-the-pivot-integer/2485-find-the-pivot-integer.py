class Solution:
    def pivotInteger(self, n: int) -> int:
        sigma, s = dict(), 0
        
        for i in range(n + 1):
            s += i
            sigma[i] = s
            
        s = 0
        for pivot in range(1, n + 1):
            s += pivot
            if s == (sigma[n] - sigma[pivot - 1]):
                return pivot
            
        return -1