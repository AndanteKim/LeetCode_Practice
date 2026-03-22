class MRUQueue:

    def __init__(self, n: int):
        self.total_elems = n
        self.bucket_size = int(n ** 0.5)
        self.data, self.index = [], []

        for num in range(1, n + 1):
            bucket_idx = (num - 1) // self.bucket_size
            if bucket_idx == len(self.data):
                self.data.append([])
                self.index.append(num)
            self.data[-1].append(num)

    def fetch(self, k: int) -> int:
        bucket_idx = bisect_right(self.index, k) - 1
        elem = self.data[bucket_idx][k - self.index[bucket_idx]]
        del self.data[bucket_idx][k - self.index[bucket_idx]]
        for i in range(bucket_idx + 1, len(self.index)):
            self.index[i] -= 1
        
        if len(self.data[-1]) >= self.bucket_size:
            self.data.append([])
            self.index.append(self.total_elems)
        self.data[-1].append(elem)

        if len(self.data[bucket_idx]) == 0:
            del self.data[bucket_idx]
            del self.index[bucket_idx]
        
        return elem


# Your MRUQueue object will be instantiated and called as such:
# obj = MRUQueue(n)
# param_1 = obj.fetch(k)