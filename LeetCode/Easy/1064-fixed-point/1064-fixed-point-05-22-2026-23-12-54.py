class Solution:
    def fixedPoint(self, arr: List[int]) -> int:
        n = len(arr)

        for i in range(n):
            if arr[i] == i:
                return i

        return -1