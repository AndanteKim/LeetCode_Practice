class Solution:
    def secondMinimum(self, n: int, edges: List[List[int]], time: int, change: int) -> int:
        adj = [[] for _ in range(n + 1)]
        
        # Build the adjacency list.
        for start, end in edges:
            adj[start].append(end)
            adj[end].append(start)
            
        dist1, dist2 = [-1] * (n + 1), [-1] * (n + 1)
        # Start with node 1, with its minimum distance.
        queue = deque([(1, 1)])
        dist1[1] = 0
        
        while queue:
            node, freq = queue.popleft()
            
            time_taken = dist1[node] if freq == 1 else dist2[node]
            # If the timeTaken falls under the red bracket, wait till the path turns green.
            if (time_taken // change) % 2:
                time_taken = change * (time_taken // change + 1) + time;
            else:
                time_taken += time
            for neighbor in adj[node]:
                if dist1[neighbor] == -1:
                    dist1[neighbor] = time_taken
                    queue.append((neighbor, 1));
                elif dist2[neighbor] == -1 and dist1[neighbor] != time_taken:
                    if neighbor == n:
                        return time_taken
                    dist2[neighbor] = time_taken
                    queue.append((neighbor, 2))
                    
        return 0