class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        ans, dirs = 0, [0, 0]
        for mv in moves:
            if mv == 'L':
                dirs[0] += 1
            elif mv == 'R':
                dirs[0] -= 1
            else:
                dirs[1] += 1

        return abs(dirs[0]) + dirs[1]