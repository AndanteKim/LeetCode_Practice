class Solution:
    def binary_search(self, row: List[int]) -> int:
        low, high = 0, len(row)
        
        while low < high:
            mid = (low + high) >> 1
            if row[mid] == 1:
                low = mid + 1
            else:
                high = mid
        return low
    
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        m, n = len(mat), len(mat[0])
        pq, ans = [], []
        
        for i, row in enumerate(mat):
            strength = self.binary_search(row)
            entry = (-strength, -i)
            if len(pq) < k or entry > pq[0]:
                heappush(pq, entry)
            if len(pq) > k:
                heapq.heappop(pq)
        
        while pq:
            strength, i = heappop(pq)
            ans.append(-i)
        
        return ans[::-1]