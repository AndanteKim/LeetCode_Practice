class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        if len(trust) < n - 1:
            return -1
        
        trust_scores = [0] * (n+1)
        
        for a, b in trust:
            trust_scores[a] -= 1
            trust_scores[b] += 1
        
        for i, score in enumerate(trust_scores[1:], start = 1):
            if score == n - 1:
                return i
            
        return -1