class Solution:
    def assignBikes(self, workers: List[List[int]], bikes: List[List[int]]) -> List[int]:
        def find_distance(worker_loc: List[int], bike_loc: List[int]) -> int:
            return abs(worker_loc[0] - bike_loc[0]) + abs(worker_loc[1] - bike_loc[1])
        
        # List of triplets (distance, worker index, bike index) for each worker_bike combination
        worker_to_bike_list = []
        pq = []
        
        for worker, worker_loc in enumerate(workers):
            curr_worker_pairs = []
            for bike, bike_loc in enumerate(bikes):
                distance = find_distance(worker_loc, bike_loc)
                curr_worker_pairs.append((distance, worker, bike))
                
            # sort the worker_to_bike_list for the current worker in reverse order
            curr_worker_pairs.sort(reverse = True)
            # add the closest bike for this worker to the priority queue
            heappush(pq, curr_worker_pairs.pop())
            # store the remaining options for the current worker in worker_to_bike_list
            worker_to_bike_list.append(curr_worker_pairs)
            
        # initialize all values to False, to signify no bikes have been taken
        bike_status = [False] * len(bikes)
        # initialize all values to -1, to signify no worker has a bike
        worker_status = [-1] * len(workers)
        
        while pq:
            # pop the worker-bike pair with smallest distance
            distance, worker, bike = heappop(pq)
            
            if not bike_status[bike]:
                # If the bike is free, assign the bike to the worker
                bike_status[bike] = True
                worker_status[worker] = bike
            else:
                # Otherwise, add the next closest bike for the current worker to the priority queue
                next_closest_bike = worker_to_bike_list[worker].pop()
                heappush(pq, next_closest_bike)
                
        return worker_status
           