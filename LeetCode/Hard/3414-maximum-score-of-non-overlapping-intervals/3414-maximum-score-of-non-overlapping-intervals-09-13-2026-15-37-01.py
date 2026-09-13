class Solution:
    def maximumWeight(self, intervals: List[List[int]]) -> List[int]:
        n = len(intervals)
        arr = [
            (intervals[i][1], intervals[i][0], intervals[i][2], i)
            for i in range(n)
        ]

        arr.sort()

        dp = [[0] * 5 for _ in range(n + 1)]
        indices = [[[] for _ in range(5)] for _ in range(n + 1)]

        for i in range(n):
            r, l, w, idx = arr[i]

            k = bisect_left(arr, (l,), hi = i)

            for j in range(1, 5):
                s1, s2 = dp[i][j], dp[k][j - 1] + w
                if s1 > s2:
                    dp[i + 1][j] = dp[i][j]
                    indices[i + 1][j] = indices[i][j].copy()
                    continue
                
                new_i = indices[k][j - 1].copy()
                new_i.append(idx)
                new_i.sort()

                if s1 == s2 and indices[i][j] < new_i:
                    new_i = indices[i][j].copy()
                dp[i + 1][j] = s2
                indices[i + 1][j] = new_i
        
        return indices[n][4]