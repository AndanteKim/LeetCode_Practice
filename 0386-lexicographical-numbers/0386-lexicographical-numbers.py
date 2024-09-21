class Node:
    def __init__(self):
        self.links = [None] * 10
        self.flag = False
        
    def contain_keys(self, ch: chr) -> bool:
        return self.links[ord(ch) - 48] != None
    
    def put(self, ch: chr, node: 'Node') -> None:
        self.links[ord(ch) - 48] = node
    
    def get(self, ch: chr) -> 'Node':
        return self.links[ord(ch) - 48]
    
    def set_end(self):
        self.flag = True
        
    def get_end(self) -> bool:
        return self.flag
        
class Trie:
    def __init__(self):
        self.root = Node()
        
    def insert(self, num: str) -> None:
        temp = self.root
        for i in range(len(num)):
            if not temp.contain_keys(num[i]):
                temp.put(num[i], Node())
            temp = temp.get(num[i])
        temp.set_end()

class Solution:
    def dfs(self, root: 'Node', curr: int, ans: List[int]) -> None:
        # Base case
        if not root:
            return
        
        if root.get_end():
            ans.append(curr)
        for i in range(0, 10):
            if root.contain_keys(chr(48 + i)):
                self.dfs(root.get(chr(48 + i)), (curr * 10) + i, ans)
    
    def lexicalOrder(self, n: int) -> List[int]:
        # Trie
        trie = Trie()
        
        for i in range(1, n + 1):
            s = str(i)
            trie.insert(s)
            
        ans = []
        self.dfs(trie.root, 0, ans)
        return ans
        