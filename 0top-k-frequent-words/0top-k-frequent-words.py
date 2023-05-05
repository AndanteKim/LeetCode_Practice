class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        frequencies = defaultdict(int)
        for word in words:
            frequencies[word] += 1
        
        heap = []
        for key in frequencies:
            heappush(heap, (frequencies[key], key))
        heap = sorted(heap, key = lambda x: (-x[0], x[1], len(x)))[:k]
        return [key for freq, key in heap]