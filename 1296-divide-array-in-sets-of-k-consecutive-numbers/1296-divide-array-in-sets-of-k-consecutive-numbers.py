class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        if len(nums) % k != 0:
            return False
        
        freq, min_heap = Counter(nums), []
        
        for key in freq:
            heappush(min_heap, key)
            
        while min_heap:
            curr = min_heap[0]
            
            for nxt in range(curr, curr + k):
                if freq[nxt] == 0:
                    return False
                
                freq[nxt] -= 1
                
                if freq[nxt] == 0:
                    if nxt != heappop(min_heap):
                        return False
                
        return True
            