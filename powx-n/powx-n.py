class Solution:
    def myPow(self, x: float, n: int) -> float:
        # Base case
        if x == 0:
            return 0
        
        if n == 0:
            return 1
        
        if n < 0:
            return 1 / self.myPow(x, -n)
        
        return x * self.myPow(x * x, (n - 1) >> 1) if n % 2 else self.myPow(x * x, n >> 1)