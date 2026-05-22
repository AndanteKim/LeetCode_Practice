class Solution:
    def fixedPoint(self, arr: List[int]) -> int:
        n = len(arr)
        ans, left, right = -1, 0, n - 1

        while left <= right:
            mid = (left + right) >> 1

            if arr[mid] == mid:
                ans = mid
                right = mid - 1
            elif arr[mid] > mid:
                right = mid - 1
            else:
                left = mid + 1

        return ans