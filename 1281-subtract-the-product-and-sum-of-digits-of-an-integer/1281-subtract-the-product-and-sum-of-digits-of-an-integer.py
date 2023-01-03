class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        prod, tot = 1, 0
        
        while n != 0:
            rem = n % 10
            prod, tot = prod * rem, tot + rem
            n //= 10
            
        return prod - tot