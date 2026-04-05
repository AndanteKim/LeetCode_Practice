class Solution:
    def judgeCircle(self, moves: str) -> bool:
        pos, dirs = [0, 0], {'U': (0, 1), 'D': (0, -1), 'L': (-1, 0), 'R': (1, 0)}

        for mv in moves:
            dx, dy = dirs[mv]
            pos[0] += dx
            pos[1] -= dy

        return pos == [0, 0]