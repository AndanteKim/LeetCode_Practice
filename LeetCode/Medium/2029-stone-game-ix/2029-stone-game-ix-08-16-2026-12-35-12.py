class Solution:
    def stoneGameIX(self, stones: List[int]) -> bool:
        cnt0 = cnt1 = cnt2 = 0

        for val in stones:
            typ = val % 3
            if typ == 0:
                cnt0 += 1
            elif typ == 1:
                cnt1 += 1
            else:
                cnt2 += 1

        if cnt0 % 2 == 0:
            return cnt1 >= 1 and cnt2 >= 1
        return abs(cnt1 - cnt2) > 2