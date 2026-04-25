class Solution:
    def maxDistance(self, side: int, points: List[List[int]], k: int) -> int:
        def check(limit: int) -> bool:
            perimeter = side * 4
            for start in arr:
                end = start + perimeter - limit
                curr = start
                for _ in range(k - 1):
                    idx = bisect_left(arr, curr + limit)
                    if idx == len(arr) or arr[idx] > end:
                        curr = -1
                        break
                    curr = arr[idx]
                if curr >= 0:
                    return True
            return False
        
        arr = []

        for x, y in points:
            if x == 0:
                arr.append(y)
            elif y == side:
                arr.append(side + x)
            elif x == side:
                arr.append(side * 3 - y)
            else:
                arr.append(side * 4 - x)

        arr.sort()

        lo, hi = 1, side
        ans = 0

        while lo <= hi:
            mid = (lo + hi) >> 1
            if check(mid):
                lo = mid + 1
                ans = mid
            else:
                hi = mid - 1

        return ans
