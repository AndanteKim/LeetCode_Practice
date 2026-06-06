class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:
        def solve(num: int) -> int:
            if num < 100:
                return 0
            
            s = str(num)
            n = len(s)

            @lru_cache(maxsize = None)
            def dfs(pos: int, prev: int, curr: int, is_lim: bool, is_lead: bool) -> Tuple[int]:
                if pos == n:
                    return 1, 0

                cnt, waviness = 0, 0
                up = int(s[pos]) if is_lim else 9
                for digit in range(up + 1):
                    new_lead = is_lead and (digit == 0)
                    # The previous number is updated to curr
                    new_prev = curr

                    # The current number is updated to digit
                    new_curr = -1 if new_lead else digit
                    sub_cnt, sub_sum = dfs(pos + 1, new_prev, new_curr, is_lim and (digit == up), new_lead)

                    if not new_lead and prev >= 0 and curr >= 0:
                        if (prev < curr and curr > digit) or (
                            prev > curr and curr < digit
                        ):
                            waviness += sub_cnt
                    cnt += sub_cnt
                    waviness += sub_sum
            
                return cnt, waviness

            _, total_sum = dfs(0, -1, -1, True, True)
            return total_sum

        return solve(num2) - solve(num1 - 1)