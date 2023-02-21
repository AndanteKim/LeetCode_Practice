class MyQueue:

    def __init__(self):
        self.stack, self.queue = [], []

    def push(self, x: int) -> None:
        self.queue.append(x)

    def pop(self) -> int:
        self.peek()
        return self.stack.pop()

    def peek(self) -> int:
        if not self.stack:
            while self.queue:
                self.stack.append(self.queue.pop())
        return self.stack[-1]

    def empty(self) -> bool:
        return not self.stack and not self.queue


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()