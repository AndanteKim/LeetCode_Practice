class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        prev, ans = 0, 0

        for dev in bank:
            cnt = 0
            for c in dev:
                if c == '1':
                    cnt += 1
            
            if cnt > 0:
                ans += prev * cnt
                prev = cnt

        return ans