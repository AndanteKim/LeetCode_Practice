class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        m = len(triangle)
        
        for row in range(1, m):
            for col in range(row + 1):
                smallest = float('inf')
                if col > 0:
                    smallest = triangle[row - 1][col - 1]
                
                if col < row:
                    smallest = min(smallest, triangle[row - 1][col])
                    
                triangle[row][col] += smallest
                
        return min(triangle[-1])