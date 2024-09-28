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
        self.head = self.tail = None

    def insertFront(self, value: int) -> bool:
        # Base case: If the deque is already full
        if self.isFull():
            return False
        
        # Insert the front depending on the length
        if not self.head:
            self.head = Node(value, None, None)
            self.tail = self.head
        else:
            new_node = Node(value, None, self.head)
            self.head.prev = new_node
            self.head = new_node
        
        self.curr_length += 1
        return True

    def insertLast(self, value: int) -> bool:
        # Base case: If the current length is already full
        if self.isFull():
            return False
        
        # Insert the last depending on the length
        if not self.tail:
            self.tail = Node(value, None, None)
            self.head = self.tail
        else:
            new_node = Node(value, self.tail, None)
            self.tail.next = new_node
            self.tail = new_node
            
        self.curr_length += 1
        return True
    
    def deleteFront(self) -> bool:
        # Base case: If the current length is already empty
        if self.isEmpty():
            return False
        
        node = self.head
        if self.curr_length == 1:
            self.head = self.tail = None
        else:
            self.head = self.head.next
            
        del node
        self.curr_length -= 1
        return True

    def deleteLast(self) -> bool:
        # Base case: If the current length is already empty
        if self.isEmpty():
            return False
        
        node = self.tail
        if self.curr_length == 1:
            self.head = self.tail = None
        else:
            self.tail = self.tail.prev
        
        del node
        self.curr_length -= 1
        return True

    def getFront(self) -> int:
        return -1 if self.isEmpty() else self.head.val

    def getRear(self) -> int:
        return -1 if self.isEmpty() else self.tail.val

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