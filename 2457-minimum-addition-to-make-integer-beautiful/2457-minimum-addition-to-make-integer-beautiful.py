class Solution:
    def digit_sum(self, n: int) -> int:
        digit = 0
        while n > 0:
            digit += n % 10
            n //= 10
        
        return digit
    
    def makeIntegerBeautiful(self, n: int, target: int) -> int:
        lst, add = 1, 0
        
        while self.digit_sum(n + add) > target:
            x = 10 ** lst
            add = x - n % x
            lst += 1
            
        return add