class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        table = dict()
        for p, word in zip(pattern, s.split()):
            if p not in table and word not in table.values():
                table[p] = word
        decode = ""
        for p in pattern:
            if p not in table:
                return False
            decode += table[p] + " "
        
        return decode[:-1] == s