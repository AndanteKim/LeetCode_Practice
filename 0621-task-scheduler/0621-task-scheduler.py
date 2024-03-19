class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        # Build frequency
        freq = Counter(tasks)
        
        # Max heap to store frequencies
        pq = [-f for f in freq.values() if f > 0]
        heapify(pq)
        
        time = 0
        # Process tasks until the heap is empty
        while pq:
            cycle, store, task_count = n + 1, [], 0
            
            # Execute tasks in each cycle
            while cycle > 0 and pq:
                curr_freq = -heappop(pq)
                if curr_freq > 1:
                    store.append(-(curr_freq - 1))
                task_count += 1
                cycle -= 1
            
            # Restore updated frequencies to the heap
            for x in store:
                heappush(pq, x)
            
            # Add time for the completed cycle
            time += task_count if not pq else n + 1
                
        return time