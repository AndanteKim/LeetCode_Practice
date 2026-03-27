class Solution:
    def areSimilar(self, mat: List[List[int]], k: int) -> bool:
        dk = k if k % 2 else -k
        m, n = len(mat), len(mat[0])

        for i in range(m):
            for j in range(n):
                if mat[i][(j + dk) % n] != mat[i][j]:
                    return False 

        return True
