class Solution:
    fuel = 0
    
    def dfs(self, node: int, parent: int, adj: Dict, seats: int) -> int:
        representatives = 1
        for child in adj[node]:
            if child != parent:
                representatives += self.dfs(child, node, adj, seats)
        
        if node != 0:
            self.fuel += ceil(representatives / seats)
        
        return representatives
        
    
    def minimumFuelCost(self, roads: List[List[int]], seats: int) -> int:
        n = len(roads) + 1
        adj = defaultdict(list)
        
        for road in roads:
            adj[road[0]].append(road[1])
            adj[road[1]].append(road[0])
        
        self.dfs(0, -1, adj, seats)
        
        return self.fuel
        