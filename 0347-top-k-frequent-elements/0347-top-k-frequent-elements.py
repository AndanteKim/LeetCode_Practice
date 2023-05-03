class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts = Counter(nums)
        heap = []
        
        for key, val in counts.items():
            heappush(heap, (val, key));
            if len(heap) > k:
                heappop(heap)
                
        return [pair[1] for pair in heap]