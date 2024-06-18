class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        job_profile = [(0, 0)]
        
        for i in range(len(difficulty)):
            job_profile.append((profit[i], difficulty[i]))
       
        # sort by decreasing order of profit
        job_profile.sort(reverse = True)
        for i in range(len(job_profile) - 1):
            job_profile[i + 1] = (job_profile[i + 1][0], min(job_profile[i][1], job_profile[i + 1][1]),)
            
        net_profit = 0
        
        for ability in worker:
            # Maximize profit using binary search
            l, r = 0, len(job_profile) - 1
            job_profit = 0
            
            while l <= r:
                mid = (l + r) >> 1
                if job_profile[mid][1] <= ability:
                    job_profit = max(job_profit, job_profile[mid][0])
                    r = mid - 1
                else:
                    l = mid + 1
            
            # Add profit of each worker to total profit
            net_profit += job_profit
        
        return net_profit