class Solution:
    def trailingZeroes(self, n: int) -> int:
        zero_cnt = 0
        
        for i in range(5, n + 1, 5):
            curr = i
            while curr % 5 == 0:
                zero_cnt += 1
                curr //= 5
                
        return zero_cnt