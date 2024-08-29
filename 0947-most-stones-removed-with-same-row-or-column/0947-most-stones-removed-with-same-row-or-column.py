# Union-Find data structure for tracking connected components
class UnionFind:
    def __init__(self, n: int):
        # Initialize all nodes as their own parent
        self.parent = [-1 for i in range(n)]
        
        # Initially, each stone is its own connected component
        self.count = n
    
    # Find the root of a node with path compression
    def find(self, node: int) -> int:
        if self.parent[node] == -1:
            return node
        
        return self.find(self.parent[node])
    
    # Union two nodes, reducing the number of connected components
    def union(self, n1: int, n2: int) -> None:
        root1, root2 = self.find(n1), self.find(n2)
        
        # If they are already in the same component, do nothing.
        if root1 == root2:
            return
        
        # Merge the components and reduce the count of connected components
        self.parent[root1] = root2
        self.count -= 1

class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        n = len(stones)
        uf = UnionFind(n)
        
        # Populate uf by connecting stones sharing the same row or column.
        for i in range(n):
            for j in range(i + 1):
                if stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1]:
                    uf.union(i, j)
                    
        return n - uf.count