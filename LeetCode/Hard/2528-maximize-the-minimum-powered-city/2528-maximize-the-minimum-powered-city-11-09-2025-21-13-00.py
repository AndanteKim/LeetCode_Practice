class Solution:
    def maxPower(self, stations: List[int], r: int, k: int) -> int:
        def check(val: int) -> bool:
            diff = cnt[:]
            total, remaining = 0, k

            for i in range(n):
                total += diff[i]

                if total < val:
                    add = val - total
                    if remaining < add:
                        return False
                    remaining -= add
                    end = min(n, i + 2 * r + 1)
                    diff[end] -= add
                    total += add
            return True
        
        n = len(stations)
        cnt = [0] * (n + 1)

        for i in range(n):
            left, right = max(0, i - r), min(n, i + r + 1)
            cnt[left] += stations[i]
            cnt[right] -= stations[i]

        lo, hi = min(stations), sum(stations) + k
        ans = 0

        while lo <= hi:
            mid = (lo + hi) >> 1
            if check(mid):
                ans = mid
                lo = mid + 1
            else:
                hi = mid - 1
        return ans