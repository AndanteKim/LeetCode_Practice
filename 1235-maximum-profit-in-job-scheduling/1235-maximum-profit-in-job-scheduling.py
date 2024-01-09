class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        
        def find_max_profit(n: int) -> int:
            for pos in range(n - 1, -1, -1):
                # It is the profit made by scheduling the current job
                curr_profit = 0
                
                # next_idx is the index of next non-conflicting job
                # bisect_left will return the iterator to the first element
                # which is equal to or greater than the element at 'jobs[pos][1]'
                next_idx = bisect_left(startTime, jobs[pos][1])
                
                # If there is a non-conflicting job possible add it's profit
                # else just consider the current job profit
                if next_idx != n:
                    curr_profit = jobs[pos][2] + dp[next_idx]
                else:
                    curr_profit = jobs[pos][2]
                
                # storing the maximum profit we can achieve by scheduling
                # non-conflicting jobs from index i to the end of array
                if pos == n - 1:
                    dp[pos] = curr_profit
                else:
                    dp[pos] = max(curr_profit, dp[pos + 1])
            
            return dp[0]
        
        jobs, n, dp = [], len(profit), [0] * 50001
        
        # storing job's details into one list
        # this will help in sorting the jobs while maintaining the other parameters\
        for i in range(n):
            jobs.append((startTime[i], endTime[i], profit[i]))
        
        jobs.sort()
        
        # binary search will be used in startTime, so store it as separate list
        for i in range(n):
            startTime[i] = jobs[i][0];
            
        return find_max_profit(n)