class Solution:
    def hIndex(self, citations: List[int]) -> int:
        highest = max(citations)
        counting = [0] * (highest + 1)
        for citation in citations:
            for i in range(citation + 1):
                counting[i] += 1
        
        for cited in range(highest, -1, -1):
            if counting[cited] >= cited:
                return cited
        
        return 0