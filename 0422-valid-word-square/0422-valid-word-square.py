class Solution:
    def validWordSquare(self, words: List[str]) -> bool:
        cols = 0
        rows = len(words)
        new_words = []
        
        for word in words:
            cols = max(cols, len(word))
        
        if cols != len(words[0]) or rows != cols:
            return False
        
        for col in range(cols):
            new_word = []
            for row in range(rows):
                if col < len(words[row]):
                    new_word.append(words[row][col])
            
            new_words.append(''.join(new_word))
        
        return words == new_words