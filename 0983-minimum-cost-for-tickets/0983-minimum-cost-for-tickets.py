class Solution:
    @lru_cache(None)
    def dp(self, i: int) -> int:
        if i > 365:
            return 0
        elif i in self.dayset:
            return min(self.dp(i + d) + c for c, d in zip(self.costs, self.durations))
        else:
            return self.dp(i+1)
        
    
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        self.dayset = set(days)
        self.durations = [1, 7, 30]
        self.costs = costs
        
        return self.dp(1)
        