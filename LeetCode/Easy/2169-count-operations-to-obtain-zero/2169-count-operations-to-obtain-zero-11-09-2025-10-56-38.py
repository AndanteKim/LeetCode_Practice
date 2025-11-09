class Solution:
    def countOperations(self, num1: int, num2: int) -> int:
        ops, n1, n2 = 0, num1, num2

        while n1 != 0 and n2 != 0:
            if n1 >= n2:
                n1 -= n2
            else:
                n2 -= n1
            ops += 1

        return ops