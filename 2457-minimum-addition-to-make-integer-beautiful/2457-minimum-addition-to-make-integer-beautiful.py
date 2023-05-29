class Solution:
    def digit_sum(self, num: int) -> int:
        s = 0;
        while num > 0:
            s += num % 10
            num //= 10
        return s
    
    def makeIntegerBeautiful(self, n: int, target: int) -> int:
        num = n
        if self.digit_sum(num) <= target:
            return 0
        
        digit = 10
        while self.digit_sum(n) > target:
            if n % digit == 0:
                digit *= 10
            n = (n // digit + 1) * digit
            digit *= 10
        return n - num