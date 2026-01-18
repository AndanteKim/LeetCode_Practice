class Solution:
    def largestMagicSquare(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])

        # Prefix sum of each row
        row_sum = [[0] * n for _ in range(m)]
        for i in range(m):
            row_sum[i][0] = grid[i][0]
            for j in range(1, n):
                row_sum[i][j] = row_sum[i][j - 1] + grid[i][j]
            
        # Prefix sum of each column
        col_sum = [[0] * n for _ in range(m)]
        for j in range(n):
            col_sum[0][j] = grid[0][j]
            for i in range(1, m):
                col_sum[i][j] = col_sum[i - 1][j] + grid[i][j]

        # Enumerate edge lengths from the largest to smallest
        for edge in range(min(m, n), 1, -1):
            # Enumerate the top-left corner position (i, j) of the square
            for i in range(m - edge + 1):
                for j in range(n - edge + 1):
                    # The value for each row, column, and diagonal should be calculated (using the first row as a sample)
                    std_sum = row_sum[i][j + edge - 1] - (
                        0 if j == 0 else row_sum[i][j - 1]
                    )

                    check = True
                    # Enumerate each row and directly compute the sum using prefix sums
                    # since we've already used the first line as a sample, we can skip the first line here.
                    for ii in range(i + 1, i + edge):
                        if (
                            row_sum[ii][j + edge - 1]
                            - (0 if j == 0 else row_sum[ii][j - 1])
                            != std_sum
                        ):
                            check = False
                            break
                    
                    if not check:
                        continue
                    
                    # Enumerate each column directly calculate the sum using prefix sums
                    for jj in range(j + 1, j + edge):
                        if (
                            col_sum[i + edge - 1][jj]
                            - (0 if i == 0 else col_sum[i - 1][jj])
                            != std_sum
                        ):
                            check = False
                            break

                    if not check:
                        continue

                    # d1 and d2 represent the sums of the two diagonals respectively.
                    # Note: d denotes diagonal
                    d1 = d2 = 0
                    # sum directly by traversing without using the prefix sum.
                    for k in range(edge):
                        d1 += grid[i + k][j + k]
                        d2 += grid[i + k][j + edge - 1 - k]

                    if d1 == std_sum and d2 == std_sum:
                        return edge

        return 1