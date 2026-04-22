class ZigzagIterator:
    def __init__(self, v1: List[int], v2: List[int]):
        self.queue, m, n = deque(), len(v1), len(v2)
        i, j = 0, 0
        while i < m or j < n:
            if i < m:
                self.queue.append(v1[i])
                i += 1
            
            if j < n:
                self.queue.append(v2[j])
                j += 1

    def next(self) -> int:
        return self.queue.popleft()

    def hasNext(self) -> bool:
        return len(self.queue) > 0

# Your ZigzagIterator object will be instantiated and called as such:
# i, v = ZigzagIterator(v1, v2), []
# while i.hasNext(): v.append(i.next())