class Solution:
    def maximumTotalDamage(self, power: List[int]) -> int:
        count = Counter(power)
        spells = [(-(10 ** 9), 0)]

        for k in sorted(count.keys()):
            spells.append((k, count[k]))
        
        n = len(spells)
        f, mx, j = [0] * n, 0, 1

        for i in range(1, n):
            while j < i and spells[j][0] < spells[i][0] - 2:
                mx = max(mx, f[j])
                j += 1
            f[i] = mx + spells[i][0] * spells[i][1]
        
        return max(f)