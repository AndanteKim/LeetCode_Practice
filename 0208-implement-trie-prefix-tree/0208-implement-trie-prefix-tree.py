class Node:
    def __init__(self, key: chr, data: str = None):
        self.key = key
        self.data = data
        self.children = {}

class Trie:

    def __init__(self):
        self.head = Node(None)

    def insert(self, word: str) -> None:
        current_node = self.head
        
        for char in word:
            if not char in current_node.children:
                current_node.children[char] = Node(char)
            current_node = current_node.children[char]
        current_node.data = word

    def search(self, word: str) -> bool:
        current_node = self.head
        
        for char in word:
            if char in current_node.children:
                current_node = current_node.children[char]
            else:
                return False
        
        if current_node.data:
            return True
        else:
            return False
            

    def startsWith(self, prefix: str) -> bool:
        current_node = self.head
        
        for char in prefix:
            if char in current_node.children:
                current_node = current_node.children[char]
            else:
                return False
            
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)