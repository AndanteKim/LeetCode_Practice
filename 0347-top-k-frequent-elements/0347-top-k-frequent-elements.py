class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        frequencies = defaultdict(int)
        for num in nums:
            frequencies[num] += 1
        
        pairs, k_freq = ((value, key) for key, value in frequencies.items()), []
        
        for pair in pairs:
            if len(k_freq) < k:
                heappush(k_freq, pair)
            elif len(k_freq) >= k and k_freq[0][0] < pair[0]:
                heappop(k_freq)
                heappush(k_freq, pair)
            
        return [key for val, key in k_freq]