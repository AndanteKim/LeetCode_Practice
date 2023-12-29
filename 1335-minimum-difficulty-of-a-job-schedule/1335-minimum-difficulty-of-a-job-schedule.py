class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        
        # Use memoization to avoid repeated computation of min_diff states
        @lru_cache(maxsize = None)
        def min_diff(i: int, remain: int) -> int:
            # Base case: finish all remaining jobs in the last day
            if remain == 1:
                return max_job_remaining[i]
        
            ans = float('inf')
            daily_max_job_diff = 0 # keep track of the maximum difficulty for today
            
            # Iterate through possible starting index for the next day
            # and ensure we have at least one job for each remaining day
            
            for j in range(i, n - remain + 1):
                daily_max_job_diff = max(daily_max_job_diff, jobDifficulty[j])
                ans = min(ans, daily_max_job_diff + min_diff(j + 1, remain - 1))
                
            return ans
        
        n = len(jobDifficulty)
        # Edge case: make sure there is at least one job per day
        if n < d:
            return -1
        
        # Precompute the maximum job difficulty for remaining jobs
        max_job_remaining = jobDifficulty[:]
        for i in range(n - 2, -1, -1):
            max_job_remaining[i] = max(max_job_remaining[i], max_job_remaining[i + 1])
        
        return min_diff(0, d)