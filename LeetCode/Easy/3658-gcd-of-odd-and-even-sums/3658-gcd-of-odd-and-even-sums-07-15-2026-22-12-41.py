class Solution:
    def gcdOfOddEvenSums(self, n: int) -> int:
        def gcd(n1: int, n2: int) -> int:
            if n1 > n2:
                n1, n2 = n2, n1

            while n2 != 0:
                n1, n2 = n2, n1 % n2

            return n1

        odd, even = n ** 2, n ** 2 + n

        return gcd(odd, even)