class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        pq, ans = [], []
        for i in range(len(mat)):
            heappush(pq, (mat[i].count(1), i))
        
        for i in range(k):
            weak, idx = heappop(pq)
            ans.append(idx)
            
        return ans