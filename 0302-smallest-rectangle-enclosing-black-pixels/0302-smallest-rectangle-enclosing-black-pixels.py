class Solution:
    def minArea(self, image: List[List[str]], x: int, y: int) -> int:
        m, n = len(image), len(image[0])
        top, bot = x, x
        left, right = y, y
        for i in range(m):
            for j in range(n):
                if image[i][j] == '1':
                    top = min(top, i)
                    bot = max(bot, i + 1)
                    left = min(left, j)
                    right = max(right, j + 1)
        
        return (bot - top) * (right - left)
        