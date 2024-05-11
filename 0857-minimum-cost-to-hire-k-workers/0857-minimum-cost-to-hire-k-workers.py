class Solution:
    def mincostToHireWorkers(self, quality: List[int], wage: List[int], k: int) -> float:
        n, ans = len(quality), float('inf')
        curr_total_quality, wage_to_quality_ratio = 0, []
        
        # Calculate wage-to-quaity ratio for each worker
        for i in range(n):
            wage_to_quality_ratio.append((wage[i] / quality[i], quality[i]))
            
        # Sort workers based on their wage-to-quality ratio
        wage_to_quality_ratio.sort(key = lambda x: x[0])
        
        # Use a heap to keep track of the highest quality workers
        highest_quality_workers = []
        
        # Iterate through workers
        for i in range(n):
            heappush(highest_quality_workers, -wage_to_quality_ratio[i][1])
            curr_total_quality += wage_to_quality_ratio[i][1]
            
            # If we have more than k workers,
            # remove the one with the highest quality
            if len(highest_quality_workers) > k:
                curr_total_quality += heappop(highest_quality_workers)
                
            # If we have exactly k workers,
            # calculate the total cost and update if it's the minimum
            if len(highest_quality_workers) == k:
                ans = min(ans, curr_total_quality * wage_to_quality_ratio[i][0])
                
        return ans