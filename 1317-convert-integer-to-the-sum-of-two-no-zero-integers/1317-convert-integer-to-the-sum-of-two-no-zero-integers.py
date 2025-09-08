class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        def is_valid(num: int) -> bool:
            while num > 0:
                if num % 10 == 0:
                    return False
                num //= 10
            return True
        
        for a in range(1, n):
            b = n - a
            valid_a, valid_b = is_valid(a), is_valid(b)

            if valid_a and valid_b:
                return [a, b]           

        return [-1, -1]