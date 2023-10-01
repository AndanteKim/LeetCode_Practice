class TrieNode:
    def __init__(self):
        self.links = [None] * 26
        self.words_ending_here = 0
        self.words_starting_here = 0


class Trie:

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        node = self.root
        for c in word:
            char_i = ord(c) - 97
            if not node.links[char_i]:
                node.links[char_i] = TrieNode()
            node = node.links[char_i]
            node.words_starting_here += 1
        node.words_ending_here += 1

    def countWordsEqualTo(self, word: str) -> int:
        node = self.root
        for c in word:
            char_i = ord(c) - 97
            if not node.links[char_i]:
                return 0
            node = node.links[char_i]
        return node.words_ending_here

    def countWordsStartingWith(self, prefix: str) -> int:
        node = self.root
        for c in prefix:
            char_i = ord(c) - 97
            if not node.links[char_i]:
                return 0
            node = node.links[char_i]
        return node.words_starting_here

    def erase(self, word: str) -> None:
        node = self.root
        for c in word:
            char_i = ord(c) - 97
            node = node.links[char_i]
            node.words_starting_here -= 1
        node.words_ending_here -= 1


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.countWordsEqualTo(word)
# param_3 = obj.countWordsStartingWith(prefix)
# obj.erase(word)