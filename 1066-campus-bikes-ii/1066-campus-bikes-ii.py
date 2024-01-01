class Solution:
    
    # Manhanttan distance
    def find_dist(self, worker: List[int], bike: List[int]) -> int:
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    
    def min_dist_sum(self, workers: List[List[int]], bikes: List[List[int]], worker_idx: int, mask: int) -> int:
        if worker_idx >= len(workers):
            return 0
        
        # If result is already calculated, return it no recursion needed
        if self.memo[mask] != -1:
            return self.memo[mask]
        
        smallest_dist_sum = float('inf')
        for bike_idx in range(len(bikes)):
            # Check if the bike at bike_idx is available
            if mask & (1 << bike_idx) == 0:
                # Adding the current distance and repeat the process for next worker
                # also changing the bit at index bike_idx to 1 to show the bike there is assigned
                smallest_dist_sum = min(smallest_dist_sum, self.find_dist(workers[worker_idx], bikes[bike_idx]) + self.min_dist_sum(workers, bikes, worker_idx + 1, mask | (1 << bike_idx)))
        
        # Memoizing the result corresponding to mask
        self.memo[mask] = smallest_dist_sum
        return self.memo[mask]
    
    def assignBikes(self, workers: List[List[int]], bikes: List[List[int]]) -> int:
        # Maximum value of mask will be 2 ^ (Number of bikes)
        # and number of bikes can be 10 at max
        # Marking all positions to -1 that signifies result
        # has not been calculated yet for this mask
        self.memo = [-1] * 1024
        
        return self.min_dist_sum(workers, bikes, 0, 0)