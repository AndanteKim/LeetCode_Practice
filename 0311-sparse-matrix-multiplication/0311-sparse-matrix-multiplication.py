class Solution:
    def multiply(self, mat1: List[List[int]], mat2: List[List[int]]) -> List[List[int]]:
        ans = [[0] * len(mat2[0]) for _ in range(len(mat1))]
        
        for row1 in range(len(mat1)):
            for col1 in range(len(mat1[0])):
                if mat1[row1][col1]:
                    for k in range(len(mat2[col1])):
                        ans[row1][k] += mat1[row1][col1] * mat2[col1][k]
                
        return ans