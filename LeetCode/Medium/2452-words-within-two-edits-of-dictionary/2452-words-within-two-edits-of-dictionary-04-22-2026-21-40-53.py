class TrieNode:
    def __init__(self):
        self.children = [None] * 26
        self.is_end = False

class Solution:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str):
        node = self.root
        for c in word:
            idx = ord(c) - 97
            if not node.children[idx]:
                node.children[idx] = TrieNode()
            node = node.children[idx]
        node.is_end = True

    def dfs(self, word: str, i: int, node: 'TrieNode', cnt: int) -> bool:
        if cnt > 2 or not node:
            return False
        
        if i == len(word):
            return node.is_end

        idx = ord(word[i]) - 97
        # No changes made
        if node.children[idx] and self.dfs(word, i + 1, node.children[idx], cnt):
            return True

        # Made changes
        if cnt < 2:
            for c in range(26):
                if c == idx:
                    continue
                
                if node.children[c] and self.dfs(word, i + 1, node.children[c], cnt + 1):
                    return True

        return False

    def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:
        for w in dictionary:
            self.insert(w)

        ans = []

        for q in queries:
            if self.dfs(q, 0, self.root, 0):
                ans.append(q)
        return ans    
    