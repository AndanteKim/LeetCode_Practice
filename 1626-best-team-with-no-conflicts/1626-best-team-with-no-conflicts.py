class Solution:
    def findMaxScore(self, ageScorePair: List[List[int]]) -> int:
        n, answer = len(ageScorePair), 0
        dp = [0] * n
        
        for i in range(n):
            dp[i] = ageScorePair[i][1]
            answer= max(answer, dp[i])
        
        for i in range(n):
            for j in range(i-1, -1, -1):
                if ageScorePair[i][1] >= ageScorePair[j][1]:
                    dp[i] = max(dp[i], ageScorePair[i][1] + dp[j])
            answer = max(answer, dp[i])
        return answer
    
    def bestTeamScore(self, scores: List[int], ages: List[int]) -> int:
        ageScorePair = [[age, score] for age, score in zip(ages, scores)]
        
        ageScorePair.sort()
        return self.findMaxScore(ageScorePair)