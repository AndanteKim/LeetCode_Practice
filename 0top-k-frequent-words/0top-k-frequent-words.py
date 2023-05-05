class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        frequencies = defaultdict(int)
        for word in words:
            frequencies[word] += 1
        
        heap = [(-frequencies[key], key) for key in frequencies]
        heapify(heap)
        
        return [heappop(heap)[1] for i in range(k)]