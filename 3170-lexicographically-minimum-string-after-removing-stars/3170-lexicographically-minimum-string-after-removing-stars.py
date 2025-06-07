class Solution:
    def clearStars(self, s: str) -> str:
        cnt, arr = [[] for _ in range(26)], list(s)
        
        for i, c in enumerate(s):
            if c != '*':
                cnt[ord(c) - 97].append(i)
            else:
                for j in range(26):
                    if cnt[j]:
                        arr[cnt[j].pop()] = '*'
                        break

        return "".join(c for c in arr if c != '*')