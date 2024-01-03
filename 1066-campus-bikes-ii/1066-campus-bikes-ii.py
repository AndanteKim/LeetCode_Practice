class Solution:
    # Manhattan Distance
    def find_distance(self, worker: List[int], bike: List[int]) -> int:
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    
    # Count the number of ones using Brian Kernighan's Algorithm
    def count_num_of_ones(self, mask: int) -> int:
        count = 0
        while mask != 0:
            mask &= mask - 1
            count += 1
        return count
    
    def assignBikes(self, workers: List[List[int]], bikes: List[List[int]]) -> int:
        m, n = len(bikes), len(workers)
        pq, visited = [], set()
        heappush(pq, (0, 0))
        
        while pq:
            current_dist_sum, current_mask = heappop(pq)
            
            # Continue if the mask is already traversed
            if current_mask in visited:
                continue
                
            # Marking the mask as visited
            visited.add(current_mask)
            # Next worker index would be equal to the number of 1's in curent_mask
            worker_index = self.count_num_of_ones(current_mask)
            
            # Return the current distance sum if all workers are covered
            if worker_index == n:
                return current_dist_sum
            
            for bike_index in range(m):
                # Checking if the bike at bike_index has been assigned or not
                if (current_mask & (1 << bike_index)) == 0:
                    next_state_distance_sum = current_dist_sum + self.find_distance(workers[worker_index], bikes[bike_index])
                    
                    # Put the next state pair into the priority queue
                    next_state_mask = current_mask | (1 << bike_index)
                    heappush(pq, (next_state_distance_sum, next_state_mask))
       
        # This statement will never be executed provided there is at least one bike per worker
        return -1;