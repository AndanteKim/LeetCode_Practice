class UnionFind:
    # For efficiency, we aren't using makeset, but instead initializing
    # all the sets at the same time in the constructor.
    def __init__(self, n: int):
        self.parent = [node for node in range(n)]
        # We use this to keep track of the size of each set.
        self.size = [1] * n

    # The find method, with path compression. There are ways of implementing
    # this elegantly with recursion, but the iterative version is easier for
    # most people to understand!
    def find(self, node: int) -> int:
        # Step1: Find the root
        root = node
        while root != self.parent[root]:
            root = self.parent[root]
        
        # Step 2: Do a second traversal, this time setting each node to point
        # directly at A as we go.
        while node != root:
            old_root = self.parent[node]
            self.parent[node] = root
            node = old_root
        return root

    # The union method, with optimization union by size. It returns True if a 
    # merge happened, False if otherwise.
    def union(self, u: int, v: int) -> bool:
        # Find the roots for A and B.
        root_u, root_v = self.find(u), self.find(v)

        # Check if u and v are already in the same set.
        if root_u == root_v:
            return False

        # We want to ensure the larger set remains the root.
        if self.size[root_u] < self.size[root_v]:
            # Make root_v the overall root.
            self.parent[root_u] = root_v

            # The size of the set rooted at v is the sum of the 2.
            self.size[root_v] += self.size[root_u]
        else:
            # Make the root_u the overall root.
            self.parent[root_v] = root_u
            # The size of the set rooted at A is the sum of the 2.
            self.size[root_u] += self.size[root_v]

        return True

class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        # Base case 1: The graph must contain n - 1 edges.
        if len(edges) != n - 1: return False

        # Create a new UnionFind object with n nodes.
        uf = UnionFind(n)

        # Add each edge. Check if a merge happened because if it didn't,
        # there must be a cycle.
        for u, v in edges:
            if not uf.union(u, v):
                return False
        
        # If we got this far, there's no cycles!
        return True