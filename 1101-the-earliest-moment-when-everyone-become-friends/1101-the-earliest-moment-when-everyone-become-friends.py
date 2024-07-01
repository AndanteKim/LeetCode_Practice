class UnionFind:
    def __init__(self, n: int):
        self.rank = [0 for _ in range(n)]
        self.root = [i for i in range(n)]
        
    def union(self, a: int, b: int) -> bool:
        group_a, group_b = self.find(a), self.find(b)
        
        # Not merged
        if group_a == group_b:
            return False
        
        # Merge the lower-rank group into the higher-rank group.
        if self.rank[group_a] > self.rank[group_b]:
            self.root[group_b] = group_a
        elif self.rank[group_a] < self.rank[group_b]:
            self.root[group_a] = group_b
        else:
            self.root[group_a] = group_b
            self.rank[group_a] += 1
        
        # Is merged
        return True
    
    def find(self, x: int) -> int:
        if self.root[x] != x:
            self.root[x] = self.find(self.root[x])
        return self.root[x]
    
class Solution:
    def earliestAcq(self, logs: List[List[int]], n: int) -> int:
        # In order to ensure that we find the earliest moment,
        # first of all, we need to sort the events in chronological order.
        logs.sort()
        uf = UnionFind(n)
        
        # Initially, we treat each individual as a separate group.
        group_cnt = n
        
        # We merge the groups along the way.
        for timestamp, a, b in logs:
            if uf.union(a, b):
                group_cnt -= 1
                
            # The moment when all individuals are connected to each other.
            if group_cnt == 1:
                return timestamp
            
        # There are still more than one groups left,
        # i.e. not everyone is connected.
        return -1