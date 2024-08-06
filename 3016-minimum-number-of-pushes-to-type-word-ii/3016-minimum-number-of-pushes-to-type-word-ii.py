class Solution:
    def minimumPushes(self, word: str) -> int:
        ans, start, push = 0, 2, 1
        pq, count = [], Counter(word)
        
        for key, val in count.items():
            heappush(pq, (-val, key))
        
        while pq:   
            freq, key = heappop(pq)
            
            ans += push * (-freq)
            start += 1
            if start > 9:
                start = 2
                push += 1
            
        return ans