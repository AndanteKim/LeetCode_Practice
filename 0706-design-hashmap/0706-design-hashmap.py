class ListNode:
    def __init__(self, key: int = -1, val: int = -1, next: Optional[ListNode] = None):
        self.key = key
        self.val = val
        self.next = next
    

class MyHashMap:
    def __init__(self):
        self.key_space = 2069
        self.hash_table = [ListNode() for _ in range(self.key_space)]

    def hash_key(self, key: int) -> int:
        return key % self.key_space
    
    def put(self, key: int, value: int) -> None:
        curr = self.hash_table[self.hash_key(key)]
        while curr.next:
            if curr.next.key == key:
                curr.next.val = value
                return
            curr = curr.next
        curr.next = ListNode(key, value)
        
    def get(self, key: int) -> int:
        curr = self.hash_table[self.hash_key(key)].next
        while curr:
            if curr.key == key:
                return curr.val
            curr = curr.next
        return -1

    def remove(self, key: int) -> None:
        curr = self.hash_table[self.hash_key(key)]
        while curr and curr.next:
            if curr.next.key == key:
                curr.next = curr.next.next
                return
            curr = curr.next

# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)