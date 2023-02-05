class Solution:
    def customSortString(self, order: str, s: str) -> str:
        d = {k : i for i, k in enumerate(order)}
        return ''.join(sorted(s, key = lambda x: d.get(x, len(s) + ord(x))))