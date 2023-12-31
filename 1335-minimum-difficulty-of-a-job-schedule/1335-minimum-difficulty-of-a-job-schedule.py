class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        n = len(jobDifficulty)
        if n < d:
            return -1
        
        # min_diff_curr_day and min_diff_prev_day record the minimum total job difficulty
        # for the current day and previous day, respectively
        min_diff_prev_day, min_diff_curr_day = [float('inf')] * n, [float('inf')] * n
        
        for day in range(d):
            # Use a monotonically decreasing stack to record job difficulties
            stack = []
            
            # The number of jobs needs to be no less than number of days passed
            for i in range(day, n):
                
                # We initialize min_diff_curr_day[i] as only performing 1 job at the i-th index.
                # At day 0, the minimum total job difficulty is to complete the 0th job only.
                if i == 0:
                    min_diff_curr_day[i] = jobDifficulty[0]
                # Otherwise, we increment min_diff_prev_day[i - 1] by the i-th job difficulty
                else:
                    min_diff_curr_day[i] = min_diff_prev_day[i - 1] + jobDifficulty[i]
                    
                # When we find the last element in the stack is smaller than or equal to current job
                # we need to pop out the element to maintain a monotonic decreasing stack
                while stack and jobDifficulty[stack[-1]] <= jobDifficulty[i]:
                    
                    # If we include all jobs with index j + 1 to i to the current day,
                    # total job difficulty of the current day will be increased.
                    # by the amount of jobDifficulty[i] - jobDifficulty[j]
                    j = stack.pop()
                    diff_incr = jobDifficulty[i] - jobDifficulty[j]
                    min_diff_curr_day[i] = min(min_diff_curr_day[i], min_diff_curr_day[j] + diff_incr)
                    
                # When the last element in the stack is larger than current element,
                # If we include all jobs with index j + 1 to the i to the current day,
                # the overall job difficulty will not change.
                if stack:
                    min_diff_curr_day[i] = min(min_diff_curr_day[i], min_diff_curr_day[stack[-1]])
                    
                # Update the monotonic stack by adding in the current index
                stack.append(i)
            min_diff_prev_day, min_diff_curr_day = min_diff_curr_day, min_diff_prev_day
        
        return min_diff_prev_day[-1]