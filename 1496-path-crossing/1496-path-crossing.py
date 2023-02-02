class Solution:
    def isPathCrossing(self, path: str) -> bool:
        curr = (0, 0)
        visited = set()
        visited.add(curr)
        
        for direction in path:
            x, y = curr
            if direction == 'N':
                curr = (x, y + 1)
            elif direction == 'E':
                curr = (x + 1, y)
            elif direction == 'S':
                curr = (x, y - 1)
            elif direction == 'W':
                curr = (x - 1, y)
            if curr in visited:
                return True
            visited.add(curr)
        return False