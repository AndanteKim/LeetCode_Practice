class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        for i in range(2, c + 1):
            if i * i > c:
                break
                
            count = 0
            if c % i == 0:
                while c % i == 0:
                    count += 1
                    c //= i
                if i % 4 == 3 and count % 2:
                    return False
                
        return c % 4 != 3