class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        # Set obstacles again to change DS
        blocked = set()
        for x, y in obstacles:
            blocked.add((x, y))
        
        dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]

        x, y, d = 0, 0, 0
        ans = 0

        for cmd in commands:
            if cmd == -1:
                d = (d + 1) % 4
            elif cmd == -2:
                d = (d + 3) % 4
            else:
                while cmd > 0:
                    nx = x + dirs[d][0]
                    ny = y + dirs[d][1]

                    if (nx, ny) in blocked:
                        break
                    x, y = nx, ny
                    ans = max(ans, x ** 2 + y ** 2)
                    cmd -= 1

        return ans