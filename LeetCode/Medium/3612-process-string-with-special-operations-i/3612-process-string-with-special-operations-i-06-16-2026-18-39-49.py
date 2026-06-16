class Solution:
    def processStr(self, s: str) -> str:
        curr = []
        for c in s:
            if c == '*':
                if len(curr) > 0:
                    curr.pop()
            elif c == '#':
                curr += curr
            elif c == '%':
                curr.reverse()
            else:
                curr.append(c)

        return "".join(curr)