class Solution:
    def multiply(self, mat1: List[List[int]], mat2: List[List[int]]) -> List[List[int]]:
        row1, col1, row2, col2 = len(mat1), len(mat1[0]), len(mat2), len(mat2[0])
        ans = [[0] * col2 for _ in range(row1)]

        for i in range(row1):
            for j in range(col2):
                curr = 0
                for k in range(col1):
                    curr += mat1[i][k] * mat2[k][j]
                ans[i][j] = curr

        return ans