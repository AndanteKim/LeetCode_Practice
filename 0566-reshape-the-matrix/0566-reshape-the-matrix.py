class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        cnt = 0
        if len(mat) == 0 or (len(mat) * len(mat[0]) != r * c): return mat
        ans = [[0] * (len(mat) * len(mat[0]) // r) for _ in range(r)]
        for i in range(len(mat)):
            for j in range(len(mat[0])):
                ans[cnt // c][cnt % c] = mat[i][j]
                cnt += 1;
        
        return ans