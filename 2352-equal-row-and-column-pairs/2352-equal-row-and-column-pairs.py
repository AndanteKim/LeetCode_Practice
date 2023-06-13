class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        cols, ans = defaultdict(int), 0
        for col in zip(*grid):
            cols[col] += 1
        
        for row in grid:
            ans += cols[tuple(row)]
        
        return ans