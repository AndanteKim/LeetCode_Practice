class Solution:
    def numberOfPowerfulInt(self, start: int, finish: int, limit: int, s: str) -> int:
        @lru_cache(maxsize = None)
        def dfs(i: int, limit_low: bool, limit_high: bool) -> int:
            # Recursive boundary
            if i == n:
                return 1
            lo = int(low[i]) if limit_low else 0
            hi = int(high[i]) if limit_high else 9

            ans = 0

            if i < pre_len:
                for digit in range(lo, min(hi, limit) + 1):
                    ans += dfs(i + 1, limit_low and digit == lo, limit_high and digit == hi)
            else:
                x = int(s[i - pre_len])
                if lo <= x <= min(hi, limit):
                    ans = dfs(i + 1, limit_low and x == lo, limit_high and x == hi)

            return ans

        low, high = str(start), str(finish)
        n = len(high)
        low = low.zfill(n)  # align digits
        pre_len = n - len(s)    # prefix length
        return dfs(0, True, True)