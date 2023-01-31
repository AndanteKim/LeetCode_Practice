class Solution:
    def queryBIT(self, BIT: List[int], age: int) -> int:
        maxScore = float('-inf')
        i = age
        while i > 0:
            maxScore = max(maxScore, BIT[i])
            i -= i & (-i)
        return maxScore
    
    def updateBIT(self, BIT: List[int], age: int, currentBest: int) -> None:
        i = age
        while i < len(BIT):
            BIT[i] = max(BIT[i], currentBest)
            i += i & (-i)
        
    
    def bestTeamScore(self, scores: List[int], ages: List[int]) -> int:
        ageScorePair = [[score, age] for score, age in zip(scores, ages)]
        ageScorePair.sort()
        
        highestAge = 0
        for age in ages:
            highestAge = max(highestAge, age)
            
        BIT = [0] * (highestAge + 1)
        answer = float('-inf')
        for ageScore in ageScorePair:
            currentBest = ageScore[0] + self.queryBIT(BIT, ageScore[1])
            self.updateBIT(BIT, ageScore[1], currentBest)
            answer = max(answer, currentBest)
        
        return answer