class Solution:
    def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
        m = len(mat)

        for k in range(4):
            for i in range(m >> 1):
                for j in range((m + 1) >> 1):
                    (
                        mat[i][j],
                        mat[m - 1 - j][i],
                        mat[m - 1 - i][m - 1 - j],
                        mat[j][m - 1 - i]
                    ) = (
                        mat[m - 1 - j][i],
                        mat[m - 1 - i][m - 1 - j],
                        mat[j][m - 1 - i], 
                        mat[i][j]
                    )

                
            if mat == target:
                return True

        return False