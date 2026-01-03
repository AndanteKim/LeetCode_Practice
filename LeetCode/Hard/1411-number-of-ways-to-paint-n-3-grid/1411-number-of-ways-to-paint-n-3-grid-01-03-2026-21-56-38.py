class Solution:
    def numOfWays(self, n: int) -> int:
        def mat_mul(A: List[List[int]], B: List[List[int]]) -> List[List[int]]:
            # Multiply 2x2 matrices modulo MOD
            m, n, p = len(A), len(B), len(B[0])
            C = [[0] * p for _ in range(m)]

            for i in range(m):
                for k in range(n):
                    for j in range(p):
                        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod

            return C

        def mat_pow(mat: List[List[int]], pow: int) -> List[List[int]]:
            # Matrix exponentiation using LSBF(binary exponentiation)
            res = [row[:] for row in I]     # Deep copy of identity matrix
            base = [row[:] for row in mat]  # Deep copy of input matrix

            while pow > 0:
                if pow & 1:
                    res = mat_mul(res, base)
                base = mat_mul(base, base)
                pow >>= 1

            return res

        if n == 1:
            return 12

        mod = 10 ** 9 + 7
        # Identity matrix and Transition matrix
        I, M = [[1, 0], [0, 1]], [[3, 2], [2, 2]]

        A = mat_pow(M, n - 1)
        total = (A[0][0] + A[0][1] + A[1][0] + A[1][1]) % mod

        return (6 * total) % mod