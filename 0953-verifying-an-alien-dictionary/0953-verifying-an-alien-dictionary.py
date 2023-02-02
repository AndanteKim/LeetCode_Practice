class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        lexico_dict = {c:i for i, c in enumerate(order)}
        
        for i in range(len(words)-1):
            word, next_word = words[i], words[i+1]
            for j in range(len(word)):
                if lexico_dict[word[j]] > lexico_dict[next_word[j]]:
                    return False
                elif word[j] == next_word[j]:
                    if j == len(next_word) - 1 and len(word) != len(next_word):
                        return False
                    continue
                else:
                    break
        return True
        