class Solution:
    def findMaxScore(self, dp: List[List[int]], ageScorePair: List[List[int]], prev: int, index: int):
        if index >= len(ageScorePair): return 0
        
        if dp[prev + 1][index] != -1:
            return dp[prev + 1][index]
        
        if (prev == -1 or ageScorePair[index][1] >= ageScorePair[prev][1]):
            dp[prev+1][index] = max(self.findMaxScore(dp, ageScorePair, prev, index + 1), ageScorePair[index][1] + self.findMaxScore(dp, ageScorePair, index, index + 1))
            return dp[prev+1][index]
        
        dp[prev + 1][index] = self.findMaxScore(dp, ageScorePair, prev, index + 1)
        return dp[prev + 1][index]
    
    def bestTeamScore(self, scores: List[int], ages: List[int]) -> int:
        ageScorePair = [[age, score] for score, age in zip(scores, ages)]
        
        ageScorePair.sort()
        
        dp = [[-1] * len(scores) for _ in range(len(scores))]
        return self.findMaxScore(dp, ageScorePair, -1, 0)
        