class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        mapping = defaultdict(lambda : '')
        for c1, c2 in zip(s,t):
            if c1 not in mapping and c2 not in mapping.values():
                mapping[c1] = c2
        
        reflect = ""
        for c in s:
            reflect += mapping[c]
            
        return reflect == t
        