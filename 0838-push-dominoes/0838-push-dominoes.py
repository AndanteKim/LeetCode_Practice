class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        n = len(dominoes)
        force = [0] * n

        # Populate forces going from left to right
        f = 0
        for i in range(n):
            if dominoes[i] == 'R':
                f = n
            elif dominoes[i] == 'L':
                f = 0
            else:
                f = max(f - 1, 0)
            force[i] += f

        # Populate forces going from right to left
        f = 0
        for i in range(n - 1, -1, -1):
            if dominoes[i] == 'L':
                f = n
            elif dominoes[i] == 'R':
                f = 0
            else:
                f = max(f - 1, 0)
            force[i] -= f
        
        return "".join('.' if f == 0 else 'R' if f > 0 else 'L' for f in force)