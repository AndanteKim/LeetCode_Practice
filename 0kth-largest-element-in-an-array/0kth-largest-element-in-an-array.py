class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        pq = []
        
        for num in nums:
            
            if len(pq) >= k:
                if pq[0] > num:
                    continue
                heappop(pq)
            heappush(pq, num)
            
        return pq[0]