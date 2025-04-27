class Solution:
    def minArea(self, image: List[List[str]], x: int, y: int) -> int:
        def dfs(r: int, c: int) -> None:
            if r < 0 or r >= len(image) or c < 0 or c >= len(image[0]) or image[r][c] == '0': return
        
            image[r][c] = '0'
            self.top = min(self.top, r)
            self.bot = max(self.bot, r + 1)
            self.left = min(self.left, c)
            self.right = max(self.right, c + 1)
            dfs(r + 1, c)
            dfs(r - 1, c)
            dfs(r, c - 1)
            dfs(r, c + 1)
        
        # Base case
        if len(image) == 0 or len(image[0]) == 0:
            return 0

        self.top = self.bot = x
        self.left = self.right = y
        dfs(x, y)
        return (self.right - self.left) * (self.bot - self.top)