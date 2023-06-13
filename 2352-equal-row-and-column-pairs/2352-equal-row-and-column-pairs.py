class TrieNode:
    def __init__(self):
        self.count = 0
        self.children = defaultdict(dict)
        
class Trie:
    def __init__(self):
        self.trie = TrieNode()
    
    def insert(self, arr: List[int]) -> None:
        my_trie = self.trie
        for num in arr:
            if num not in my_trie.children:
                my_trie.children[num] = TrieNode()
            my_trie = my_trie.children[num]
        my_trie.count += 1
    
    def search(self, arr: List[int]) -> int:
        my_trie = self.trie
        for num in arr:
            if num in my_trie.children:
                my_trie = my_trie.children[num]
            else:
                return 0
        return my_trie.count

class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        my_trie, count = Trie(), 0
        n = len(grid)
        
        for row in grid:
            my_trie.insert(row)
        
        for c in range(n):
            cols = [grid[i][c] for i in range(n)]
            count += my_trie.search(cols)
        
        return count
        