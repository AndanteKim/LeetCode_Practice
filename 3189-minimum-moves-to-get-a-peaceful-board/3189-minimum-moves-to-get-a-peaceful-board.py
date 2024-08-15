class Solution:
    def minMoves(self, rooks: List[List[int]]) -> int:
        ans, n = 0, len(rooks)
        
        # Store the count of rooks in each row and colimn
        row, col = [0] * n, [0] * n
        for r in rooks:
            row[r[0]] += 1
            col[r[1]] += 1
            
        row_min_moves, col_min_moves = 0, 0
        
        for i in range(n):
            # Difference between the rooks count at row and column and one.
            row_min_moves += row[i] - 1
            col_min_moves += col[i] - 1
            
            # Moves required for row and column constraints
            ans += abs(row_min_moves) + abs(col_min_moves)
            
        return ans