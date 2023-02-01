class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        rows = [tuple(row) for row in grid]
        columns = [tuple(col) for col in zip(*grid)]
        look_up_row, look_up_col = defaultdict(int), defaultdict(int)
        for r, c in zip(rows, columns):
            look_up_row[r] += 1
            look_up_col[c] += 1
        
        intersection, ans = look_up_row.keys() & look_up_col.keys(), 0
        
        for matrix in intersection:
            ans += look_up_row[matrix] * look_up_col[matrix]
        
        return ans