class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        m, n = len(s1), len(s2)
        costs = [[0] * (n + 1) for _ in range(m + 1)]

        for i in range(1, m + 1):
            costs[i][0] = costs[i - 1][0] + ord(s1[i - 1])
        
        for i in range(1, n + 1):
            costs[0][i] = costs[0][i - 1] + ord(s2[i - 1])

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if s1[i - 1] == s2[j - 1]:
                    costs[i][j] = costs[i - 1][j - 1]
                else:
                    costs[i][j] = min(
                        ord(s1[i - 1]) + costs[i - 1][j],
                        ord(s2[j - 1]) + costs[i][j - 1]
                    )

        return costs[m][n]