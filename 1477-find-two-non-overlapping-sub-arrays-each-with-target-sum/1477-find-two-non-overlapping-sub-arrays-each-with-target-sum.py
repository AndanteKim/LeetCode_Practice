class Solution:
    def minSumOfLengths(self, arr: list[int], target: int) -> int:
        pos = {0: -1}
        n, s = len(arr), 0
        ans, min_l = n + 1, n

        for i, x in enumerate(arr):
            s += x
            if s - target in pos:
                j = pos[s - target]
                length = i - j
                ans = min(ans, length + (n if j == -1 else arr[j]))
                min_l = min(min_l, length)
            arr[i] = min_l
            pos[s] = i

        return -1 if ans == n + 1 else ans