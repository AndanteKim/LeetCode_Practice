class Solution:
    def climbStairs(self, n: int) -> int:
        sqrt5 = 5 ** 0.5
        phi, psi = (1 + sqrt5) / 2, (1 - sqrt5) / 2
        
        return int((phi ** (n + 1) - psi ** (n + 1)) / sqrt5)