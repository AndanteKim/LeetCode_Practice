class UnionFind:
    def __init__(self, n: int):
        self.components = n
        self.parents = list(range(n))
        
    def find(self, node: int) -> int:
        if self.parents[node] != node:
            self.parents[node] = self.find(self.parents[node])
        return self.parents[node]
    
    def union(self, parent: int, child: int) -> bool:
        parent_parent = self.find(parent)
        child_parent = self.find(child)
        
        if child_parent != child or parent_parent == child_parent:
            return False
        
        self.components -= 1
        self.parents[child_parent] = parent_parent
        return True

class Solution:
    def validateBinaryTreeNodes(self, n: int, leftChild: List[int], rightChild: List[int]) -> bool:
        uf = UnionFind(n)
        for node in range(n):
            for child in [leftChild[node], rightChild[node]]:
                if child == -1:
                    continue
            
                if not uf.union(node, child):
                    return False
    
        return uf.components == 1