class MyStack:

    def __init__(self):
        self.queue = deque()
        self.q_to_stack = deque()

    def push(self, x: int) -> None:
        self.queue.append(x)
        while self.queue:
            self.q_to_stack.appendleft(self.queue.popleft())

    def pop(self) -> int:
        return self.q_to_stack.popleft()

    def top(self) -> int:
        return self.q_to_stack[0]

    def empty(self) -> bool:
        return not self.q_to_stack


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()