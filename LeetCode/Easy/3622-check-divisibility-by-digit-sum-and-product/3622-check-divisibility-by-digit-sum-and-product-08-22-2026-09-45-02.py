class Solution:
    def checkDivisibility(self, n: int) -> bool:
        def _sum(num: int) -> int:
            total = 0
            while num > 0:
                total += num % 10
                num //= 10

            return total

        def _prod(num: int) -> int:
            total = 1

            while num > 0:
                total *= num % 10
                num //= 10

            return total

        d_sum, d_prod = _sum(n), _prod(n)

        return n % (d_sum + d_prod) == 0