class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        counter, pq = Counter(nums), []
        for num, freq in counter.items():
            heappush(pq, (freq, -num))
        
        ans = []
        while pq:
            freq, n = heappop(pq)
            ans.extend([-n] * freq)
        
        return ans