class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        if len(mat) == 1: return mat[0][0]
        ans, length = 0, len(mat)
        
        if length % 2 == 0:
            for i in range(length):
                ans += mat[i][i]
                ans += mat[length-1-i][i]
        else:
            for i in range(length):
                ans += mat[i][i]
                ans += mat[length-1-i][i]
            ans -= mat[length//2][length//2]
        return ans