class MyCircularDeque:

    def __init__(self, k: int):
        self.queue = [0] * k
        self.head, self.tail = 0, k - 1
        self.size, self.length = 0, k

    def insertFront(self, value: int) -> bool:
        if self.isFull():
            return False
        
        self.head = (self.head - 1 + self.length) % self.length
        self.queue[self.head] = value
        self.size += 1
        return True

    def insertLast(self, value: int) -> bool:
        if self.isFull():
            return False
        
        self.tail = (self.tail + 1) % self.length
        self.queue[self.tail] = value
        self.size += 1
        return True

    def deleteFront(self) -> bool:
        if self.isEmpty():
            return False
        self.head = (self.head + 1) % self.length
        self.size -= 1
        return True

    def deleteLast(self) -> bool:
        if self.isEmpty():
            return False
        self.tail = (self.tail - 1 + self.length) % self.length
        self.size -= 1
        return True

    def getFront(self) -> int:
        return -1 if self.isEmpty() else self.queue[self.head]

    def getRear(self) -> int:
        return -1 if self.isEmpty() else self.queue[self.tail]

    def isEmpty(self) -> bool:
        return self.size == 0

    def isFull(self) -> bool:
        return self.size == self.length


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()