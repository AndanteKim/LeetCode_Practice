class Solution:
    def tribonacci(self, n: int) -> int:
        t_0 = 0
        if n == 0: return t_0
        t_1 = 1
        if n == 1: return t_1
        t_2 = t_0 + t_1
        if n == 2: return t_2
        t_3 = t_0 + t_1 + t_2
        i, ans = 3, 0
        for _ in range(i, n+1):
            t_3 = t_0 + t_1 + t_2
            t_0, t_1, t_2 = t_1, t_2, t_3
            ans = t_3
            
        return ans