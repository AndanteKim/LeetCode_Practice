class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        def find_max_profit() -> int:
            pq, max_profit = [], 0
            
            for i in range(self.n):
                start, end, profit = jobs[i]
            
                # keep popping while the heap is not empty and
                # jobs are not conflicting
                # update the value of max_profit
                while pq and start >= pq[0][0]:
                    _, curr_profit = heappop(pq)
                    max_profit = max(max_profit, curr_profit)
                    
                # push the job with combined profit
                # if no non-conflicting job is present max_profit will be 0
                heappush(pq, (end, profit + max_profit))
                
            # update the value of max_profit by comparing with
            # profit of jobs that exits in the heap
            while pq:
                _, curr_profit = heappop(pq)
                max_profit = max(max_profit, curr_profit)
            
            return max_profit
        
        jobs, self.n = [], len(profit)
        
        for i in range(self.n):
            jobs.append((startTime[i], endTime[i], profit[i]))
            
        jobs.sort()
        
        return find_max_profit()