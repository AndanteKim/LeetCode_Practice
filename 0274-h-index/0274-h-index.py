class Solution:
    def hIndex(self, citations: List[int]) -> int:
        n = len(citations)
        papers = [0] * (n + 1)
        
        for c in citations:
            papers[min(n, c)] += 1
            
        k, s = n, papers[n]
        
        while k > s:
            k -= 1
            s += papers[k]
        return k
        