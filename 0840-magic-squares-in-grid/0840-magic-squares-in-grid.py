class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        ans, m, n = 0, len(grid), len(grid[0])
        
        for row in range(m - 2):
            for col in range(n - 2):
                if self._is_magic_square(grid, row, col):
                    ans += 1
        return ans
                
    def _is_magic_square(self, grid: List[List[int]], row: int, col: int) -> bool:
        # The sequences are each repeated twice to account for
        # the different possible starting points of the sequence
        # in the magic square
        sequence = "2943816729438167"
        sequence_reversed = "7618349276183492"
        
        border = []
        # Flattened indices for bordering elements of 3x3 grid
        border_indices = [0, 1, 2, 5, 8, 7, 6, 3]
        
        for i in border_indices:
            num = grid[row + (i // 3)][col + (i % 3)]
            border.append(str(num))
            
        border_converted = "".join(border)
        
        # Make sure the sequence starts at one of the corners
        return (grid[row][col] % 2 == 0 and (sequence.find(border_converted) != -1 or \
                                            sequence_reversed.find(border_converted) != -1)\
                and grid[row + 1][col + 1] == 5)