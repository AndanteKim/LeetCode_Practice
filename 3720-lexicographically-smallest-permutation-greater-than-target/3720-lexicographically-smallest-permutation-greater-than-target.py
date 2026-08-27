class Solution:
    def lexGreaterPermutation(self, s: str, target: str) -> str:
        cnt = [0] * 26
        for c in s:
            cnt[ord(c) - 97] += 1
        
        n = len(target)
        ans = []

        for i in range(n):
            t = ord(target[i]) - 97

            if cnt[t] > 0:
                cnt[t] -= 1

                if self.can_greater(cnt, target[i + 1:]):
                    ans.append(target[i])
                    continue
                cnt[t] += 1

            for c in range(t + 1, 26):
                if cnt[c] > 0:
                    cnt[c] -= 1
                    ans.append(chr(c + 97))

                    ans.append("".join(chr(j + 97) * cnt[j] for j in range(26)))
                    return "".join(ans)

            return ""

        return ""

    def can_greater(self, cnt: List[int], suffix: str) -> bool:
        max_str = "".join(
            chr(i + 97) * cnt[i] for i in range(25, -1, -1) if cnt[i] > 0
        )

        return max_str > suffix