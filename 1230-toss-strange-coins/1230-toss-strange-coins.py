class Solution:
    def findProbability(self, index: int, target: int, n: int, prob: List[float], memo: List[List[float]]) -> int:
        if target < 0:
            return 0
        
        if index == n:
            if target == 0:
                return 1
            else:
                return 0
        
        if memo[index][target] != -1:
            return memo[index][target]
        
        memo[index][target] = self.findProbability(index + 1, target - 1, n, prob, memo) * prob[index] + self.findProbability(index + 1, target, n, prob, memo) * (1 - prob[index])
        
        return memo[index][target]
    
    def probabilityOfHeads(self, prob: List[float], target: int) -> float:
        memo = [[-1] * (target + 1) for _ in range(len(prob))]
        
        return self.findProbability(0, target, len(prob), prob, memo)