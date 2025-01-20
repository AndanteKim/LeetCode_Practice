class Solution:
    def firstCompleteIndex(self, arr: List[int], mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        location = dict()

        for i in range(m):
            for j in range(n):
                location[mat[i][j]] = (i, j)
        
        rows, cols = [0] * m, [0] * n

        for i in range(m * n):
            (r, c) = location[arr[i]]

            rows[r] += 1
            cols[c] += 1

            if rows[r] == n or cols[c] == m:
                return i

        return -1