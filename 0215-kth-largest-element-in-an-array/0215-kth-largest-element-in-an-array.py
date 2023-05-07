class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        heap = []
        for num in nums:
            if len(heap) >= k:
                if num >= heap[0]:
                    heappop(heap)
                    heappush(heap, num)
                continue
            heappush(heap, num)
        
        return heap[0]