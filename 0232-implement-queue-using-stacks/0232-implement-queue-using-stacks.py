class MyQueue:

    def __init__(self):
        self.stack = []

    def push(self, x: int) -> None:
        if self.stack:
            new_stack = [x]
            self.stack = self.stack[::-1]
            while self.stack:
                new_stack.append(self.stack.pop())
            self.stack = new_stack
        else:
            self.stack.append(x)

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