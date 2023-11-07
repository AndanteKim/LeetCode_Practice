class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        heap = []
        for i in range(len(dist)):
            heap.append(dist[i] / speed[i])
        
        heapify(heap)
        ans = 0
        
        while heap:
            if heappop(heap) <= ans:
                break
            ans += 1
        return ans
            