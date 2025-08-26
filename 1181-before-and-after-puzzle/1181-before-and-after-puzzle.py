class Solution:
    def beforeAndAfterPuzzles(self, phrases: List[str]) -> List[str]:
        n = len(phrases)
        sp = []
        for phrase in phrases:
            words = phrase.split(" ")
            sp.append((words[0], words[-1]))

        m = set()
        for i in range(n):
            for j in range(n):
                if i == j:
                    continue
                if sp[i][0] == sp[j][1]:
                    combined = phrases[j] + phrases[i][len(sp[i][0]) :]
                    m.add(combined)

        ret = sorted(list(m))
        return ret