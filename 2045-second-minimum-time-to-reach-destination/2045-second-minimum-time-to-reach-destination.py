class Solution:
    def secondMinimum(self, n: int, edges: List[List[int]], time: int, change: int) -> int:
        adj = [[] for _ in range(n + 1)]
        
        for start, end in edges:
            adj[start].append(end)
            adj[end].append(start)
        
        # dist1[i] stores the minimum time taken to reach node i from node 1. dist2[i] stores
        # the second minimum time taken to reach node from node 1. Freq[i] stores the number of
        # times a node is popped out of the heap.
        dist1, dist2 = [float("inf")] * (n + 1), [float("inf")] * (n + 1)
        freq, min_heap = [0] * (n + 1), [(0, 1)]
        dist1[1] = 0
        
        while min_heap:
            time_taken, node = heappop(min_heap)
            
            freq[node] += 1
            
            # If the node is being visited for the second time and is 'n', return the answer.
            if freq[node] == 2 and node == n:
                return time_taken
            
            # If the current light is red, wait till the path turns green.
            if (time_taken // change) % 2:
                time_taken = change * (time_taken // change + 1) + time
            else:
                time_taken += time
                
            for neighbor in adj[node]:
                # Ignore nodes having already popped out twice.
                if freq[neighbor] == 2:
                    continue
                
                # Update dist1 if it's more than the current time_taken and store its value in
                # dist2 since that becomes the second minimum value now.
                if dist1[neighbor] > time_taken:
                    dist2[neighbor] = dist1[neighbor]
                    dist1[neighbor] = time_taken
                    heappush(min_heap, (time_taken, neighbor))
                elif dist2[neighbor] > time_taken and dist1[neighbor] != time_taken:
                    dist2[neighbor] = time_taken
                    heappush(min_heap, (time_taken, neighbor))
                    
        return 0