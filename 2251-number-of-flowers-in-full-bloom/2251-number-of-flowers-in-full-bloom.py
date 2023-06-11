class Solution:
    def fullBloomFlowers(self, flowers: List[List[int]], people: List[int]) -> List[int]:
        bloom_start, bloom_end = sorted(start for start, end in flowers), sorted(end for start, end in flowers)
        
        return [bisect_right(bloom_start, time) - bisect_left(bloom_end, time) for time in people]