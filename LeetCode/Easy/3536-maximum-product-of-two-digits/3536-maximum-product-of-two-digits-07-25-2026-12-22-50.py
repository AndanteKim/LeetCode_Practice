class Solution:
    def maxProduct(self, n: int) -> int:
        min_digits = []
        while n > 0:
            heappush(min_digits, -(n % 10))
            n //= 10
        
        return heappop(min_digits) * heappop(min_digits)