class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        
        for i in range(n, 101):
            sum_, num = 1, i

            while num > 0:
                sum_ *= num % 10
                num //= 10

            if sum_ % t == 0:
                return i

        return -1