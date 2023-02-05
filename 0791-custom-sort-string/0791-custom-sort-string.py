class Solution:
    def customSortString(self, order: str, s: str) -> str:
        d = defaultdict(lambda: len(order))
        
        for i, o in enumerate(order):
            d[o] = i
        return ''.join(sorted(s, key = lambda x: d[x]))