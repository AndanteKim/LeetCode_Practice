class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        n = len(jobDifficulty)
        if n < d:
            return -1
        
        # Initialize the min_diff matrix to record the minimum difficulty of the job schedule
        min_diff = [[float('inf')] * n + [0] for _ in range(d + 1)]
        
        for days_remaining in range(1, d + 1):
            for i in range(n - days_remaining + 1):
                daily_max_job_diff = 0
                
                for j in range(i + 1, n - days_remaining + 2):
                    # Use daily_max_job_diff to record maximum job difficulty
                    daily_max_job_diff = max(daily_max_job_diff, jobDifficulty[j - 1])
                    min_diff[days_remaining][i] = min(min_diff[days_remaining][i], daily_max_job_diff + \
                                                      min_diff[days_remaining - 1][j])
        
        return -1 if min_diff[d][0] == float('inf') else min_diff[d][0]