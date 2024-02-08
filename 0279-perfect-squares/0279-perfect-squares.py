class Solution:
    def is_square(self, n: int) -> bool:
        sq = int(sqrt(n))
        return sq * sq == n
    
    def numSquares(self, n: int) -> int:
        # four-square and three-square theorems
        while n & 3 == 0:
            n >>= 2     # reducing the 4^k factor from number
        
        if n & 7 == 7: # mod 8
            return 4
        
        if self.is_square(n):
            return 1
        
        # check if the number can be decomposed into sum of two squares
        for i in range(1, int(n ** 0.5) + 1):
            if self.is_square(n - i * i):
                return 2
        
        # bottom case from the three-square theorem
        return 3