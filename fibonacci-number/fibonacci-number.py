class Solution:
    def fib(self, n: int) -> int:
        # Base case
        if n <= 1:
            return n
        
        # Bottom up with space optimization
        first, second = 0, 1
        for i in range(2, n + 1):
            third = first + second
            first, second = second, third
            
        return second