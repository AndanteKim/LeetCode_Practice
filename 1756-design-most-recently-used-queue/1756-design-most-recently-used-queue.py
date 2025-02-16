class MRUQueue:

    def __init__(self, n: int):
        self.nums = SortedList((v, v) for v in range(1, n + 1))

    def fetch(self, k: int) -> int:
        ans = self.nums[k - 1][1]
        last_pos = self.nums[-1][0]
        del self.nums[k - 1]
        self.nums.add((last_pos + 1, ans))

        return ans

# Your MRUQueue object will be instantiated and called as such:
# obj = MRUQueue(n)
# param_1 = obj.fetch(k)