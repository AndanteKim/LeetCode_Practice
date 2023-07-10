class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        @lru_cache(maxsize = None)
        def pascal(i: int, j: int) -> int:
            if j == 1 or i == 1 or i == j:
                return 1
            return pascal(i - 1, j - 1) + pascal(i, j - 1)
        
        dp = []
        
        for j in range(1, numRows + 1):
            row = []
            for i in range(1, j + 1):
                row.append(pascal(i, j))
            dp.append(row)
        return dp
        
        