class Solution:
    def assignBikes(self, workers: List[List[int]], bikes: List[List[int]]) -> int:
        @lru_cache(maxsize = None)
        def dp(i: int, curr: int, workers_unoccupied: int, bikes_unoccupied: int) -> int:
            # Base case
            if i >= m:
                if workers_unoccupied == 0:
                    return curr
                return float('inf')
            
            min_distances = float('inf')
            
            if workers_unoccupied & (1 << i):
                workers_unoccupied -= (1 << i)
                for bike_idx, dist in distances[i]:
                    if bikes_unoccupied & (1 << bike_idx):
                        min_distances = min(min_distances, dp(i + 1, curr + dist, workers_unoccupied, bikes_unoccupied - (1 << bike_idx)))
            else:
                min_distances = min(min_distances, dp(i + 1, curr, workers_unoccupied, bikes_unoccupied))
            
            return min_distances
            
        
        n, m = len(workers), len(bikes)
        distances = defaultdict(list)
        for i in range(n):
            for j in range(m):
                distances[i].append((j, abs(bikes[j][0] - workers[i][0]) + abs(bikes[j][1] - workers[i][1]))) 
        workers_unoccupied, bikes_unoccupied = sum(1 << i for i in range(n)), sum(1 << i for i in range(m))
        return dp(0, 0, workers_unoccupied, bikes_unoccupied)