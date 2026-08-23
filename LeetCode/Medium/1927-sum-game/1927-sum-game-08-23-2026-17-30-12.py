class Solution:
    def sumGame(self, num: str) -> bool:
        sum_l = q_l = 0
        sum_r = q_r = 0
        n = len(num)

        for i in range(n):
            if i < (n >> 1):
                if num[i] == '?':
                    q_l += 1
                else:
                    sum_l += int(num[i])
            else:
                if num[i] == '?':
                    q_r += 1
                else:
                    sum_r += int(num[i])


        if (q_l + q_r) % 2:
            return True
        
        ds, dq = sum_l - sum_r, q_r - q_l

        return ds != (dq >> 1) * 9