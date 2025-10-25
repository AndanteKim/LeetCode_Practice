class Solution:
    def totalMoney(self, n: int) -> int:
        k = n // 7
        F, L = 28, 28 + (k - 1) * 7
        arithmetic_sum = k * (F + L) >> 1

        monday, final_week = 1 + k, 0
        
        for day in range(n % 7):
            final_week += monday + day
        
        return arithmetic_sum + final_week