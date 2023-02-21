class MyQueue:

    def __init__(self):
        self.stack, self.queue = [], []

    def push(self, x: int) -> None:
        if self.stack == []:
            self.front = x
        while self.stack:
            self.queue.append(self.stack.pop())
        self.queue.append(x)
        while self.queue:
            self.stack.append(self.queue.pop())

    def pop(self) -> int:
        res = self.stack.pop()
        if self.stack:
            self.front = self.stack[-1]
        return res

    def peek(self) -> int:
        return self.front

    def empty(self) -> bool:
        return self.stack == []


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()