class Solution:
    def findLonelyPixel(self, picture: List[List[str]]) -> int:
        m, n = len(picture), len(picture[0])
        row_cnt, col_cnt = [0] * m, [0] * n

        for i in range(m):
            for j in range(n):
                if picture[i][j] == 'B':
                    row_cnt[i] += 1
                    col_cnt[j] += 1
        
        ans = 0
        for i in range(m):
            for j in range(n):
                if picture[i][j] == 'B' and row_cnt[i] == 1 and col_cnt[j] == 1:
                    ans += 1

        return ans

