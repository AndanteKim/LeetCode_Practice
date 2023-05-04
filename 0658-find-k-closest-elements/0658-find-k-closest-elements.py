class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        heap = []
        
        for num in arr:
            dist = abs(num - x)
            heappush(heap, (-dist, -num))
            if len(heap) > k:
                heappop(heap)
        
        return sorted([-num for dist, num in heap])