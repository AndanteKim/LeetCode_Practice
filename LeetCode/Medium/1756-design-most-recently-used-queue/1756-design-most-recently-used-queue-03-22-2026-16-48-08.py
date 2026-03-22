class MRUQueue:

    def __init__(self, n: int):
        self.queue = deque(range(1, n + 1))

    def fetch(self, k: int) -> int:
        front_list = []
        for _ in range(k - 1):
            front_list.append(self.queue.popleft())
        ans = self.queue.popleft()

        while front_list:
            self.queue.appendleft(front_list.pop())
        self.queue.append(ans)
        return ans


# Your MRUQueue object will be instantiated and called as such:
# obj = MRUQueue(n)
# param_1 = obj.fetch(k)