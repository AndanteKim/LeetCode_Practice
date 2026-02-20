class Solution:
    def makeLargestSpecial(self, s: str) -> str:
        if not s:
            return s
        
        mountains = []
        anchor = bal = 0

        for i, x in enumerate(s):
            bal += 1 if x == '1' else -1

            if bal == 0:
                mountains.append("1{}0".format(
                    self.makeLargestSpecial(s[anchor + 1: i])
                ))
                anchor = i + 1

        mountains.sort(reverse = True)
        return "".join(mountains)