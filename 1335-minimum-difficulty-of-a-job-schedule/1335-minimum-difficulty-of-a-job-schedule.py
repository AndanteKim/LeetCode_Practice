class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        n = len(jobDifficulty)
        if n < d:
            return -1
        
        # Initialize min_diff, prev_diff matrix to record the minimum difficulty of the job schedule
        min_diff_next_day = [float('inf')] * (n + 1)
        min_diff_next_day[-1] = 0
        
        for days_remaining in range(1, d + 1):
            min_diff_curr_day = [float('inf')] * (n + 1)
            min_diff_curr_day[-1] = 0
            for i in range(n - days_remaining + 1):
                daily_max_job_diff = 0
                for j in range(i + 1, n - days_remaining + 2):
                    # Use daily_max_job_diff to record maximum job difficulty
                    daily_max_job_diff = max(daily_max_job_diff, jobDifficulty[j - 1])
                    min_diff_curr_day[i] = min(min_diff_curr_day[i], daily_max_job_diff + min_diff_next_day[j])
            min_diff_next_day = min_diff_curr_day
        
        return -1 if min_diff_next_day[0] == float('inf') else min_diff_next_day[0]