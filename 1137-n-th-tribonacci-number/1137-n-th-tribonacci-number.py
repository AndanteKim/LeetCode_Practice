class Solution:
    def tribonacci(self, n: int) -> int:
        if n <= 2:
            return 1 if n == 2 else 1 if n == 1 else 0
        
        t_n0, t_n1, t_n2 = 0, 1, 1
        
        for i in range(n - 2):
            t_n3 = t_n0 + t_n1 + t_n2
            t_n0, t_n1, t_n2 = t_n1, t_n2, t_n3
            
        return t_n3