class Solution:
    def assignBikes(self, workers: List[List[int]], bikes: List[List[int]]) -> int:
        # Manhattan distance
        def find_dist(worker: List[int], bike: List[int]) -> int:
            return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1])

        def min_dist_sum(worker_idx: int, curr_dist_sum: int) -> None:
            if worker_idx >= m:
                self.ans = min(self.ans, curr_dist_sum)
                return
            
            # If the current distance sum is greater than the smallest result
            # foudn then stop exploring this combination of workers and bikes
            if curr_dist_sum >= self.ans:
                return
            
            for bike_idx in range(n):
                if not visited[bike_idx]:
                    visited[bike_idx] = True
                    min_dist_sum(worker_idx + 1, curr_dist_sum + find_dist(workers[worker_idx], bikes[bike_idx]))
                    visited[bike_idx] = False
        
        self.ans, visited, m, n = float('inf'), [0] * 10, len(workers), len(bikes)
        min_dist_sum(0, 0)
        return self.ans