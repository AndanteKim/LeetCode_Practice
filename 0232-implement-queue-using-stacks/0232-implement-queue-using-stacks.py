class MyQueue:

    def __init__(self):
        self.stack, self.queue = [], []

    def push(self, x: int) -> None:
        while self.stack:
            self.queue.append(self.stack.pop())
        self.queue.append(x)
        while self.queue:
            self.stack.append(self.queue.pop())

    def pop(self) -> int:
        return self.stack.pop()

    def peek(self) -> int:
        return self.stack[-1]

    def empty(self) -> bool:
        return not self.stack


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()