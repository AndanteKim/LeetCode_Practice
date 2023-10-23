class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        start = 1
        while start < n:
            start *= 4
            
        return start == n