class Solution:
    def validWordSquare(self, words: List[str]) -> bool:
        vertical_words = ["".join(mat) for mat in zip_longest(*words, fillvalue = "")]
        
        for cross, vertical in zip(words, vertical_words):
            if cross != vertical:
                return False
        return True