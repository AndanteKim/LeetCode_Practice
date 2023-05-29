class Solution:
    def digit_sum(self, n: int) -> int:
        return sum([int(c) for c in str(n)])
    
    def makeIntegerBeautiful(self, n: int, target: int) -> int:
        lst, add = 1, 0
        
        while self.digit_sum(n + add) > target:
            x = 10 ** lst
            add = x - n % x
            lst += 1
            
        return add