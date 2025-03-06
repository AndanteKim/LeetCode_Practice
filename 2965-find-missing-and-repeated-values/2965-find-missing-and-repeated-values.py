class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        # Get grid dimensions
        n = len(grid)
        total = n ** 2

        # Calculate actual sums from grid
        sum_val = sum(num for row in grid for num in row)
        sqr_sum = sum(num * num for row in grid for num in row)

        # Calculate differences from expected sums
        # Expected sum: n(n + 1) / 2, Expected square sum: n(n + 1)(2n + 1) / 6
        sum_diff = sum_val - (total * (total + 1) >> 1)
        sqr_diff = sqr_sum - total * (total + 1) * (2 * total + 1) // 6

        # Using math: If x is repeated and y is missing
        # sum_diff = x - y
        # sqr_diff = x**2 - y**2
        repeat = (sqr_diff // sum_diff + sum_diff) >> 1
        missing = (sqr_diff // sum_diff - sum_diff) >> 1

        return [repeat, missing]