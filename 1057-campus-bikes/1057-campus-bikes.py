class Solution:
    def assignBikes(self, workers: List[List[int]], bikes: List[List[int]]) -> List[int]:
        def find_distance(worker_loc: List[int], bike_loc: List[int]) -> int:
            return abs(worker_loc[0] - bike_loc[0]) + abs(worker_loc[1] - bike_loc[1])
        
        min_dist = float('inf')
        dist_to_pairs = defaultdict(list)
        
        for worker, worker_loc in enumerate(workers):
            for bike, bike_loc in enumerate(bikes):
                distance = find_distance(worker_loc, bike_loc)
                dist_to_pairs[distance].append((worker, bike))
                min_dist = min(min_dist, distance)
            
        curr_dist = min_dist
        
        # Init all values to False, to signify no bikes have been taken
        bike_status = [False] * len(bikes)
        
        # Init all values to -1, to signify no worker has a bike
        worker_status = [-1] * len(workers)
        
        # keep track of how many worker-bike pairs have been made
        pair_count = 0
        
        # While all workers have not been assigned a bike
        while pair_count < len(workers):
            for worker, bike in dist_to_pairs[curr_dist]:
                if worker_status[worker] == -1 and not bike_status[bike]:
                    # If both worker and bike are free, assign them to each other
                    bike_status[bike] = True
                    worker_status[worker] = bike
                    pair_count += 1
            curr_dist += 1
        
        return worker_status