class Solution:
    def canBeEqual(self, s1: str, s2: str) -> bool:
        for i in range(2):
            ch_s1, ch_s2 = {s1[i], s1[i + 2]}, {s2[i], s2[i + 2]}
            if ch_s1 != ch_s2:
                return False

        return True