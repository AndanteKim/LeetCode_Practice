class CustomStack:

    def __init__(self, maxSize: int):
        # List to store stack elements
        self._stack = [0] * maxSize
        
        # List to store incremenets for lazy propagation
        self._inc = [0] * maxSize
        
        # Current top index of the stack
        self._top = -1

    def push(self, x: int) -> None:
        if self._top < len(self._stack) - 1:
            self._top += 1
            self._stack[self._top] = x

    def pop(self) -> int:
        if self._top < 0:
            return -1
        
        # Calculate the actual value with increment
        res = self._stack[self._top] + self._inc[self._top]
        
        # Propagate the increment to the element below
        if self._top > 0:
            self._inc[self._top - 1] += self._inc[self._top]
        
        # Reset the increment for this position
        self._inc[self._top] = 0
        self._top -= 1
        return res

    def increment(self, k: int, val: int) -> None:
        if self._top >= 0:
            # Apply increment to the topmost element of the range
            index = min(self._top, k - 1)
            self._inc[index] += val


# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)