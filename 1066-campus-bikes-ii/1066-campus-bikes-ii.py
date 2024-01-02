class Solution:
    # Count the number of ones using Brian Kernighan's Algorithm
    def count_num_of_ones(self, mask: int) -> int:
        cnt = 0
        while mask != 0:
            mask &= (mask - 1)
            cnt += 1
        return cnt
    
    # Manhanttan Distance
    def find_dist(self, worker: List[int], bike: List[int]) -> int:
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1])
    
    def min_dist_sum(self, workers: List[List[int]], bikes: List[List[int]]) -> int:
        m, n, smallest_dist_sum = len(bikes), len(workers), float('inf')
        
        # 0 signifies that no bike has been assigned and distance sum for no assigning any bike is equal to 0
        self.dp[0] = 0
        
        # Traverse over all the possible values of mask
        for mask in range((1 << m)):
            next_worker_idx = self.count_num_of_ones(mask)
            
            # If mask has more number of 1's than the number of workers
            # Then, we can update our anser accordingly
            if next_worker_idx >= n:
                smallest_dist_sum = min(smallest_dist_sum, self.dp[mask])
                continue
            
            for bike_idx in range(m):
                # Checking if the bike at bike_idx has already been assigned
                if (mask & (1 << bike_idx)) == 0:
                    new_mask = (1 << bike_idx) | mask
                    
                    # Updating the distance sum for new mask
                    self.dp[new_mask] = min(self.dp[new_mask], self.dp[mask] + self.find_dist(workers[next_worker_idx], bikes[bike_idx]))
        
        return smallest_dist_sum
     
    def assignBikes(self, workers: List[List[int]], bikes: List[List[int]]) -> int:
        # Maximum value of mask will be 2 ^ (Number of bikes)
        # And number of bikes can be 10 at max
        self.dp = [float('inf')] * 1024
        return self.min_dist_sum(workers, bikes)
        