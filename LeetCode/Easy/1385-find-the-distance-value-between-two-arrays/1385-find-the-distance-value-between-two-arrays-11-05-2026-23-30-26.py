class Solution:
    def findTheDistanceValue(self, arr1: list[int], arr2: list[int], d: int) -> int:
        ans = 0
        arr2.sort()

        for a1 in arr1:
            p = bisect_left(arr2, a1)
            if p == len(arr2) or abs(a1 - arr2[p]) > d:
                if p == 0 or abs(a1 - arr2[p - 1]) > d:
                    ans += 1

        return ans