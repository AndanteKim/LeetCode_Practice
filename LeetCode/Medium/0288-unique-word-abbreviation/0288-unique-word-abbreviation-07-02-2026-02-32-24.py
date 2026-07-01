class ValidWordAbbr:
    def to_abbr(self, s: str) -> str:
        n = len(s)
        if n <= 2:
            return s
        return s[0] + str(n - 2) + s[-1]

    def __init__(self, dictionary: List[str]):
        self.abbr_dict = defaultdict(set)

        for s in dictionary:
            abbr = self.to_abbr(s)
            self.abbr_dict[abbr].add(s)

    def isUnique(self, word: str) -> bool:
        abbr = self.to_abbr(word)
        words = self.abbr_dict[abbr]
        return words == set() or (len(words) == 1 and word in words)


# Your ValidWordAbbr object will be instantiated and called as such:
# obj = ValidWordAbbr(dictionary)
# param_1 = obj.isUnique(word)