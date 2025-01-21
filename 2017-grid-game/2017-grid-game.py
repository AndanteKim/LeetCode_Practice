class Solution:
    def gridGame(self, grid: List[List[int]]) -> int:
        first_row_sum = sum(grid[0])
        second_row_sum = 0
        min_sum = float('inf')

        for i in range(len(grid[0])):
            first_row_sum -= grid[0][i]

            # Find the minimum maximum value out of first_row_sum and
            # second_row_sum.
            min_sum = min(min_sum, max(first_row_sum, second_row_sum))
            second_row_sum += grid[1][i]

        return min_sum