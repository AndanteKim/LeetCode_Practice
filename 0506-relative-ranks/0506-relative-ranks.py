class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        n = len(score)
        pq, ans, awards = [], [""] * n, []
        
        for i in range(n):
            heappush(pq, (-score[i], i))
            
            if i == 0:
                awards.append("Gold Medal")
            elif i == 1:
                awards.append("Silver Medal")
            elif i == 2:
                awards.append("Bronze Medal")
            else:
                awards.append(str(i + 1))
            
        curr = 0
        while pq:
            rank, idx = heappop(pq)
            ans[idx] = awards[curr]
            curr += 1
        
        return ans