class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        below_row, n = triangle[-1], len(triangle)
        
        for row in range(n - 2, -1, -1):
            curr_row = []
            for col in range(row + 1):
                smallest = min(below_row[col], below_row[col + 1])
                curr_row.append(triangle[row][col] + smallest)
            below_row = curr_row
        return below_row[0]