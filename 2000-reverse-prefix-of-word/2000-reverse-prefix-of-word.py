class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        location, i = word.find(ch), 0
        split_word = [c for c in word]
        while i < location:
            split_word[i], split_word[location] = split_word[location], split_word[i]
            i += 1
            location -= 1
        return "".join(split_word)
            