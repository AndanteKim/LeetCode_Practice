class UnionFind:
    _parent, _rank = [], []
    _count = 0
    
    def __init__(self, size: int):
        self._parent = [-1] * size
        self._rank = [0] * size
        self._count = 0
    
    def addLand(self, x: int) -> None:
        if self._parent[x] >= 0: return
        self._parent[x] = x
        self._count += 1
    
    def isLand(self, x: int) -> bool:
        if self._parent[x] >= 0:
            return True
        else:
            return False
    
    def numberOfIslands(self) -> int:
        return self._count
    
    def find(self, x: int) -> List[int]:
        if self._parent[x] != x:
            self._parent[x] = self.find(self._parent[x])
        return self._parent[x]
    
    def union_set(self, x: int, y: int) -> None:
        xset, yset = self.find(x), self.find(y)
        if xset == yset: return
        elif self._rank[xset] < self._rank[yset]:
            self._parent[xset] = yset
        elif self._rank[xset] > self._rank[yset]:
            self._parent[yset] = xset
        else:
            self._parent[yset] = xset
            self._rank[xset] += 1
        self._count -= 1

        
class Solution:
    
    def numIslands2(self, m: int, n: int, positions: List[List[int]]) -> List[int]:
        x = [-1, 1, 0, 0]
        y = [0, 0, -1, 1]
        
        dsu = UnionFind(m * n)
        answer = []
        
        for position in positions:
            landPosition = position[0] * n + position[1]
            dsu.addLand(landPosition)
            
            for i in range(4):
                neighborX = position[0] + x[i]
                neighborY = position[1] + y[i]
                neighborPosition = neighborX * n + neighborY
                
                if neighborX >= 0 and neighborX < m and neighborY >= 0 and neighborY < n and dsu.isLand(neighborPosition):
                    dsu.union_set(landPosition, neighborPosition)
            answer.append(dsu.numberOfIslands())
        
        return answer