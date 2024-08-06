class Solution:
    def minimumPushes(self, word: str) -> int:
        # Frequency map to store count of each letter
        freq_map = Counter(word)
        
        # Priority queue to store frequencies in descending order
        pq = [-freq for freq in freq_map.values()]
        heapify(pq)
        
        ans, i = 0, 0
        
        # Calculate total number of presses
        while pq:
            ans += (1 + (i // 8)) * -heappop(pq)
            i += 1
            
        return ans