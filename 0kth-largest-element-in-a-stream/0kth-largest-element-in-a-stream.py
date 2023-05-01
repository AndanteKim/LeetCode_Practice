class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.pq, self.k = [], k
        for num in nums:
            if len(self.pq) >= self.k:
                if self.pq[0] <= num:
                    heappop(self.pq)
                    heappush(self.pq, num)
                continue
            heappush(self.pq, num)
            
    def add(self, val: int) -> int:
        if len(self.pq) >= self.k and self.pq[0] <= val:
            heappop(self.pq)
            heappush(self.pq, val)
        elif len(self.pq) < self.k:
            heappush(self.pq, val)
        return self.pq[0]


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)