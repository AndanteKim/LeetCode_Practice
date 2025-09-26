class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        prev_row = triangle[0]

        for row in range(1, len(triangle)):
            curr_row = []
            for col in range(row + 1):
                smallest = float('inf')
                if col > 0:
                    smallest = prev_row[col - 1]
                
                if col < row:
                    smallest = min(smallest, prev_row[col])
                curr_row.append(triangle[row][col] + smallest)
            prev_row = curr_row
        
        return min(prev_row)