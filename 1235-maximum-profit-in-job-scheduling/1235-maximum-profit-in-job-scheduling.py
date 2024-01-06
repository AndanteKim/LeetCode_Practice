class Solution:
    def dp(self, jobs: List[List[int]], start: List[List[int]], n: int, pos: int) -> int:
        # 0 profit if we have already iterated over all the jobs
        if pos == n:
            return 0
        
        # we have already calculated the answer, so no need to go into recursion
        if self.memo[pos] != -1:
            return self.memo[pos]
        
        # next_idx is the index of next non-conflicting job
        # bisect_left will return the iterator to the first element which is equal to or greater than the element at jobs[pos][1]
        next_idx = bisect_left(start, jobs[pos][1])
        
        # find the maximum profit of our two options: skipping or scheduling the current job
        max_profit = max(self.dp(jobs, start, n, pos + 1), jobs[pos][2] + self.dp(jobs, start, n, next_idx))
        self.memo[pos] = max_profit
        return max_profit
    
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        # marking all values to -1, so that we can differentiate
        # if we have already calculated the answer or not
        n, self.memo, jobs = len(startTime), [-1] * 50001, []
        
        # Storing job's details into one list
        # this will help in sorting the jobs while maintaining the other parameters
        for i in range(n):
            jobs.append([startTime[i], endTime[i], profit[i]])
        
        jobs.sort()
        
        # binary search will be used in startTime so store it as separate list
        for i in range(n):
            startTime[i] = jobs[i][0]
        return self.dp(jobs, startTime, n, 0)