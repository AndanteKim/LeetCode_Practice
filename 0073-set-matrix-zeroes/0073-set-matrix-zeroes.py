class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        queue = deque()
        m, n = len(matrix), len(matrix[0])
        
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    queue.append((i, j))
        
        while queue:
            curr_r, curr_c = queue.popleft()

            for i in range(n):
                matrix[curr_r][i] = 0
            
            for i in range(m):
                matrix[i][curr_c] = 0