# Union-Find data structure for tracking connected components
class UnionFind:
    def __init__(self, n: int):
        # Initialize all nodes as their own parent
        self.parent = [-1] * n
        
        # Initialize the count of connected components
        self.component_count = 0
        
        # Initialize the set to track unique nodes
        self.unique_nodes = set()
        
    # Find the root of a node with path compression
    def find(self, node: int) -> int:
        # If node isn't marked, increase the component count.
        if node not in self.unique_nodes:
            self.component_count += 1
            self.unique_nodes.add(node)
            
        if self.parent[node] == -1:
            return node
        
        self.parent[node] = self.find(self.parent[node])
        return self.parent[node]
    
    # Union two nodes, reducing the number of connected components
    def union(self, n1: int, n2: int) -> None:
        root1, root2 = self.find(n1), self.find(n2)
        
        # If they're already in the same component, do nothing
        if root1 == root2:
            return
        
        # Merge the components and reduce the component count
        self.parent[root1] = root2
        self.component_count -= 1

class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        # Initialize UnionFind with a large enough range to handle coordinates
        uf = UnionFind(20002)
        
        # Union stones sharing the same row or column
        for i in range(len(stones)):
            # Offset y - coordinates to avoid conflict with x-coordinates
            uf.union(stones[i][0], stones[i][1] + 10001)
            
        return len(stones) - uf.component_count