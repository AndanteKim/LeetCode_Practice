class UnionFind:
    def __init__(self, nums: List[int]):
        self.root = {num: num for num in nums}
        self.rank = {num: 0 for num in nums}
        self.size = {num: 1 for num in nums}
    
    def find(self, x: int) -> int:
        if self.root[x] != x:
            self.root[x] = self.find(self.root[x])
        return self.root[x]
    
    def union_sets(self, x: int, y: int) -> None:
        root_x, root_y = self.find(x), self.find(y)
        
        if self.rank[root_x] > self.rank[root_y]:
            self.root[root_y] = root_x
            self.size[root_x] += self.size[root_y]
        elif self.rank[root_x] < self.rank[root_y]:
            self.root[root_x] = root_y
            self.size[root_y] += self.size[root_x]
        else:
            self.root[root_y] = root_x
            self.rank[root_x] += 1
            self.size[root_x] += self.size[root_y]
            
    def get_maxsize(self):
        max_size = 0
        for sz in self.size:
            max_size = max(max_size, self.size[sz])
            
        return max_size

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        # Union-Find(Disjoint Set)
        # Each num is initially an island, we want to find out
        # the largest continent -> Disjoint set
        """
        1. Build disjoint set for each num.
        2. Try connect each set with its consecutive number
        3. Return the largest set size
        
        Complexity:
        - Time: O(n * alpha(n)) where n is the length of nums
        - space: O(n)
        """
        
        uf = UnionFind(nums)
        
        for num in uf.root:
            if num + 1 in uf.root:
                uf.union_sets(num, num + 1)
        return uf.get_maxsize()