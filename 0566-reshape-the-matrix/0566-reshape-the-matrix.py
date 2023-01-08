class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        row, col = 0, 0
        if len(mat) * len(mat[0]) != r * c: return mat
        ans = [[0] * (len(mat) * len(mat[0]) // r) for _ in range(r)]
        
        for i in range(len(ans)):
            for j in range(len(ans[0])):
                ans[i][j] = mat[row][col]
                if col == len(mat[0]) - 1:
                    row += 1
                    col = 0
                else:
                    col += 1
        
        return ans