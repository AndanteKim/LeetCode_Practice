class UnionFind:
    def __init__(self, n: int):
        self.count = n
        self.parent, self.rank = [i for i in range(n)], [0] * n
        
    def find(self, x: int) -> int:
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        
        return self.parent[x]
    
    def union(self, x: int, y: int) -> None:
        root_x, root_y = self.find(x), self.find(y)
        
        if root_x != root_y:
            if self.rank[root_x] < self.rank[root_y]:
                self.parent[root_x] = root_y
            elif self.rank[root_x] > self.rank[root_y]:
                self.parent[root_y] = root_x
            else:
                self.parent[root_y] = root_x
                self.rank[root_x] += 1
            self.count -= 1
        
    def connected(self, x: int, y: int) -> bool:
        return self.find(x) == self.find(y)
        
    def get_count(self) -> int:
        return self.count

class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if not board or not board[0]:
            return
        
        m, n = len(board), len(board[0])
        uf = UnionFind(m * n + 1)
        
        for i in range(m):
            for j in range(n):
                # If 'O' node is on the boundry, connect it to the dummy node
                if i == 0 or i == m - 1 or j == 0 or j == n - 1 and board[i][j] == 'O':
                    uf.union(i * n + j, n * m)
                elif board[i][j] == 'O':
                    if board[i - 1][j] == 'O':
                        uf.union(i * n + j, (i - 1) * n + j)
                        
                    if board[i + 1][j] == 'O':
                        uf.union(i * n + j, (i + 1) * n + j)
                        
                    if board[i][j - 1] == 'O':
                        uf.union(i * n + j, i * n + j - 1)
                    
                    if board[i][j + 1] == 'O':
                        uf.union(i * n + j, i * n + j + 1)
                        
        for i in range(m):
            for j in range(n):
                # If the dummy node is not connected to the dummy node, it's captured
                if not uf.connected(i * n + j, n * m):
                    board[i][j] = 'X'
        
                    
                
        