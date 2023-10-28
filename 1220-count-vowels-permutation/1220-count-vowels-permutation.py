class Solution:
    def countVowelPermutation(self, n: int) -> int:
        permutations = [[1] * n for _ in range(5)]
        MOD = 1_000_000_007
        
        for i in range(1, n):
            # 'a'
            permutations[0][i] = (permutations[1][i - 1] + permutations[2][i - 1] + permutations[4][i - 1]) % MOD
            # 'e'
            permutations[1][i] = (permutations[0][i - 1] + permutations[2][i - 1]) % MOD
            # 'i'
            permutations[2][i] = (permutations[1][i - 1] + permutations[3][i - 1]) % MOD
            # 'o'
            permutations[3][i] = permutations[2][i - 1] % MOD
            # 'u'
            permutations[4][i] = (permutations[2][i - 1] + permutations[3][i - 1]) % MOD
        
        return sum(permutations[i][n - 1] for i in range(5)) % MOD