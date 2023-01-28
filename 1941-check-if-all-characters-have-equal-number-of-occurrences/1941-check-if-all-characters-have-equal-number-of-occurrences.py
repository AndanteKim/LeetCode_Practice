class Solution:
    def areOccurrencesEqual(self, s: str) -> bool:
        lookup = defaultdict(int)
        for c in s:
            lookup[c] += 1
        
        return True if len(set(lookup.values())) == 1 else False