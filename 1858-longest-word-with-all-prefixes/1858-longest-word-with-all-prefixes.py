class TrieNode:
    def __init__(self):
        self.is_word = False
        self.children = dict()

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        curr = self.root
        curr.is_word = True
        for c in word:
            if c not in curr.children:
                curr.children[c] = TrieNode()
            curr = curr.children[c]
        curr.is_word = True

    def search(self, word: str) -> bool:
        curr = self.root

        for c in word:
            if not curr.is_word:
                return False
            curr = curr.children[c]

        return True

class Solution:
    def longestWord(self, words: List[str]) -> str:
        root = Trie()
        for word in words:
            curr = root
            curr.insert(word)

        words.sort(key = lambda x: (-len(x), x))

        for word in words:
            if root.search(word):
                return word

        return ""
        