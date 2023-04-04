class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        rows = len(mat)
        if rows == 0:
            return mat
        cols = len(mat[0])
        dist = [[float('inf')] * cols for _ in range(rows)]
        
        for i in range(rows):
            for j in range(cols):
                if not mat[i][j]:
                    dist[i][j] = 0
                else:
                    if i > 0:
                        dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1)
                    if j > 0:
                        dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1)
        
        for i in range(rows - 1, -1, -1):
            for j in range(cols - 1, -1, -1):
                if i < rows - 1:
                    dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1)
                if j < cols - 1:
                    dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1)
        
        return dist