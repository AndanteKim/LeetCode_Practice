class TrieNode:
    def __init__(self):
        self.isWord = False
        self.children = defaultdict(TrieNode)

class Trie:
    def __init__(self):
        self.root = TrieNode()
        
    def insert(self, word):
        node = self.root
        for i, c in enumerate(word):
            node = node.children[c]
            if node.isWord:
                if self.exists(word[i+1:]):
                    return False
                else:
                    continue
        node.isWord = True
        return True
    
    
    def exists(self, word):
        node = self.root
        for i, c in enumerate(word):
            if c in node.children:
                node = node.children[c]
                if node.isWord:
                    if i == len(word) - 1 or self.exists(word[i+1:]):
                        return True
                    else:
                        continue
            else:
                return False
                
        
class Solution:
    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
        trie = Trie()
        
        return [word for word in sorted(words, key = len) if not trie.insert(word)]