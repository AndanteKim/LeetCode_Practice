class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        lookup1, lookup2 = Counter(s1), Counter(s2)
        
        if lookup1 != lookup2:
            return False
        else:
            switch = 0
            for c1, c2 in zip(s1,s2):
                if c1 != c2:
                    switch += 1
            if switch == 2 or switch == 0:
                return True
        return False