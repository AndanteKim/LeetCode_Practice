class Node:
    def __init__(self, val: int, prev: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.prev = prev
        self.next = next

class MyCircularDeque:
    def __init__(self, k: int):
        # Create a double linked list
        self.length = k
        self.curr_length = 0
        self.front = self.last = None

    def insertFront(self, value: int) -> bool:
        # Base case: If the deque is already full
        if self.isFull():
            return False
        
        # Insert the front depending on the length
        node = Node(value)
        if self.curr_length == 0:
            self.front = self.last = node
            self.front.next = self.last
            self.front.prev = self.last
            self.last.prev = self.front
            self.last.next = self.front
        else:
            self.front.prev = node
            node.next = self.front
            node.prev = self.last
            self.last.next = node
            self.front = self.front.prev
        self.curr_length += 1
        
        return True

    def insertLast(self, value: int) -> bool:
        # Base case: If the current length is already full
        if self.isFull():
            return False
        
        # Insert the last depending on the length
        node = Node(value)
        if self.curr_length == 0:
            self.front = self.last = node
            self.front.next = self.last
            self.front.prev = self.last
            self.last.prev = self.front
            self.last.next = self.front
        else:
            self.last.next = node
            node.prev = self.last
            node.next = self.front
            self.last = self.last.next
        self.curr_length += 1
        
        return True
    
    def deleteFront(self) -> bool:
        # Base case: If the current length is already empty
        if self.isEmpty():
            return False
        
        node = self.front
        if self.curr_length == 1:
            self.front = self.last = None
        else:
            self.front = self.front.next
            self.front.prev = self.last
            self.last.next = self.front
        del node
        self.curr_length -= 1
        return True

    def deleteLast(self) -> bool:
        # Base case: If the current length is already empty
        if self.isEmpty():
            return False
        
        node = self.last
        if self.curr_length == 1:
            self.front = self.last = None
        else:
            self.last = self.last.prev
            self.last.next = self.front
            self.front.prev = self.last
        del node
        self.curr_length -= 1
        return True

    def getFront(self) -> int:
        return -1 if self.curr_length == 0 else self.front.val

    def getRear(self) -> int:
        return -1 if self.curr_length == 0 else self.last.val

    def isEmpty(self) -> bool:
        return self.curr_length == 0

    def isFull(self) -> bool:
        return self.curr_length == self.length


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