class Solution:
    def rotatedDigits(self, n: int) -> int:
        def dp(i: int, eq_flag: bool, inv_flag: bool) -> int:
            if i == len(A):
                return inv_flag
            
            if (i, eq_flag, inv_flag) not in memo:
                ans = 0
                for d in range(A[i] + 1 if eq_flag else 10):
                    if d in {3, 4, 7}:
                        continue
                    ans += dp(i + 1, eq_flag and d == A[i],
                              inv_flag or d in {2, 5, 6, 9})
                
                memo[i, eq_flag, inv_flag] = ans
            return memo[i, eq_flag, inv_flag]
        
        A, memo = list(map(int, str(n))), dict()

        return dp(0, True, False)