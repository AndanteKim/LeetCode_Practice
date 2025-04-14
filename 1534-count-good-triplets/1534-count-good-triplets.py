class Solution:
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        ans, n = 0, len(arr)
        total = [0] * 1001

        for j in range(n):
            for k in range(j + 1, n):
                if abs(arr[j] - arr[k]) <= b:
                    lj, rj = arr[j] - a, arr[j] + a
                    lk, rk = arr[k] - c, arr[k] + c
                    l, r = max(0, lj, lk), min(1000, rj, rk)
                    if l <= r:
                        ans += total[r] if l == 0 else total[r] - total[l - 1]

            for k in range(arr[j], 1001):
                total[k] += 1

        return ans