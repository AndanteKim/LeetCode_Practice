class TrieNode:
    def __init__(self):
        self.is_end = False
        self.children = [None] * 26
        
class Trie:
    def __init__(self):
        self.root = TrieNode()
        
    def insert(self, word: str) -> None:
        curr = self.root
        for c in word:
            if curr.children[ord(c) - 97] is None:
                curr.children[ord(c) - 97] = TrieNode()
            curr = curr.children[ord(c) - 97]
        curr.is_end = True
        
    # Find the shortest root of the word in the trie
    def shortest_root(self, word: str) -> str:
        curr = self.root
        for i in range(len(word)):
            c = word[i]
            if curr.children[ord(c) - 97] is None:
                # There is not a corresponding root in the trie
                return word
            curr = curr.children[ord(c) - 97]
            if curr.is_end:
                return word[: i + 1]
        
        # There is not a corresponding root in the trie
        return word

class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        words = sentence.split()
        dict_trie = Trie()
        for word in dictionary:
            dict_trie.insert(word)
            
        # Replace each word in the sentence with the corresponding shortest root
        for word in range(len(words)):
            words[word] = dict_trie.shortest_root(words[word])
            
        return " ".join(words)