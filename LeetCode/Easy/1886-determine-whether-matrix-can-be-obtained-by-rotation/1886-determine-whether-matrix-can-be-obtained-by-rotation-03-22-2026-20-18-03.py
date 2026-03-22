class Solution:
    def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
        def rotate() -> None:
            for i in range(m):
                for j in range(i + 1, n):
                    mat[i][j], mat[j][i] = mat[j][i], mat[i][j]

            for i in range(n):
                mat[i] = mat[i][::-1]
        
        m, n = len(mat), len(mat[0])
        for _ in range(4):
            if mat == target:
                return True

            rotate()

        return False