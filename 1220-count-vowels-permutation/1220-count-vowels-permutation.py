class Solution:
    def countVowelPermutation(self, n: int) -> int:
        a_cnt = e_cnt = i_cnt = o_cnt = u_cnt = 1
        MOD = 1_000_000_007
        for i in range(1, n):
            a_new_cnt = (e_cnt + i_cnt + u_cnt) % MOD
            e_new_cnt = (a_cnt + i_cnt) % MOD
            i_new_cnt = (e_cnt + o_cnt) % MOD
            o_new_cnt = i_cnt % MOD
            u_new_cnt = (i_cnt + o_cnt) % MOD
            
            a_cnt, e_cnt, i_cnt, o_cnt, u_cnt = a_new_cnt, e_new_cnt, i_new_cnt, o_new_cnt, u_new_cnt
            
        return (a_cnt + e_cnt + i_cnt + o_cnt + u_cnt) % MOD