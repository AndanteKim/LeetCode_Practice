class Solution:
    def rotateTheBox(self, boxGrid: List[List[str]]) -> List[List[str]]:
        m, n = len(boxGrid), len(boxGrid[0])
        ans = [['.'] * m for _ in range(n)]

        for r in range(m):
            p = n - 1

            for c in range(n - 1, -1, -1):
                if boxGrid[r][c] == '*':
                    ans[c][m - 1 - r] = '*'
                    p = c - 1
                elif boxGrid[r][c] == '#':
                    ans[p][m - 1 - r] = '#'
                    p -= 1
        
        return ans