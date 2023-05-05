class Pair:
    def __init__(self, word: str, freq: int):
        self.word = word
        self.freq = freq
    
    def __lt__(self, p: 'Pair') -> bool:
        return self.freq < p.freq or (self.freq == p.freq and self.word > p.word)


class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        cnt = Counter(words)
        h = []
        for word, freq in cnt.items():
            heappush(h, Pair(word, freq))
            if len(h) > k:
                heappop(h)
        return [p.word for p in sorted(h, reverse = True)]