class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        # Find maximum ability in the worker array
        max_ability = max(worker)
        jobs = [0] * (max_ability + 1)
        
        for i in range(len(difficulty)):
            if difficulty[i] <= max_ability:
                jobs[difficulty[i]] = max(jobs[difficulty[i]], profit[i])
        
        # Take maxima of prefixes
        for i in range(1, max_ability + 1):
            jobs[i] = max(jobs[i], jobs[i - 1])
            
        net_profit = 0
        for ability in worker:
            net_profit += jobs[ability]
            
        return net_profit
            