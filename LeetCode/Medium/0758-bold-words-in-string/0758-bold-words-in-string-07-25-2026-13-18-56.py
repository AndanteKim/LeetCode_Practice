class Solution:
    def boldWords(self, words: List[str], s: str) -> str:
        n = len(s)
        mask = [False] * n

        for i in range(n):
            prefix = s[i:]
            for word in words:
                if prefix.startswith(word):
                    for j in range(i, min(i + len(word), n)):
                        mask[j] = True

        ans = []

        for incl, grp in groupby(zip(s, mask), lambda z: z[1]):
            if incl:
                ans.append("<b>")
            ans.append("".join(z[0] for z in grp))
            if incl:
                ans.append("</b>")

        return "".join(ans)