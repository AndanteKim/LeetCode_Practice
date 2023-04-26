class Solution:
    def addDigits(self, num: int) -> int:
        
        while num >= 10:
            curr = 0
            while num > 0:
                curr += num % 10
                num //= 10
            num = curr
        
        return num