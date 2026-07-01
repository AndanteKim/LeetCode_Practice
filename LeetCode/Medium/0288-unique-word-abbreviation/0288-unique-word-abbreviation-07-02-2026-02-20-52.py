class ValidWordAbbr:

    def __init__(self, dictionary: List[str]):
        self.dict = dictionary

    def isUnique(self, word: str) -> bool:
        n = len(word)

        for s in self.dict:
            if s == word:
                continue
            
            m = len(s)
            if m == n and s[0] == word[0] and s[-1] == word[-1]:
                return False

        return True

# Your ValidWordAbbr object will be instantiated and called as such:
# obj = ValidWordAbbr(dictionary)
# param_1 = obj.isUnique(word)