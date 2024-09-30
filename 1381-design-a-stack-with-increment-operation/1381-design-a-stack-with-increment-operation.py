class CustomStack:
    def __init__(self, maxSize: int):
        self.stack = [-1] * maxSize
        self.ptr = -1

    def push(self, x: int) -> None:
        if self.ptr + 1 >= len(self.stack):
            return
        self.ptr += 1
        self.stack[self.ptr] = x

    def pop(self) -> int:
        if self.ptr < 0:
            return -1
        
        ans = self.stack[self.ptr]
        self.stack[self.ptr] = -1
        self.ptr -= 1
        return ans

    def increment(self, k: int, val: int) -> None:
        for i in range(0, min(k, len(self.stack))):
            self.stack[i] += val


# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)