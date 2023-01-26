class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        unique_sentence = set(sentence)
        return True if len(unique_sentence) == 26 else False