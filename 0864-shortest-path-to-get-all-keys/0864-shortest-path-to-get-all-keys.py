class Solution:
    def shortestPathAllKeys(self, grid: List[str]) -> int:
        queue = deque()
        m, n = len(grid), len(grid[0])
        
        seen = defaultdict(set)
        key_set, lock_set = set(), set()
        all_keys = 0
        start_r, start_c = -1, -1
        for i in range(m):
            for j in range(n):
                cell = grid[i][j]
                if cell in 'abcdef':
                    all_keys += (1 << (ord(cell) - ord('a')))
                    key_set.add(cell)
                if cell in 'ABCDEF':
                    lock_set.add(cell)
                if cell == '@':
                    start_r, start_c = i, j
                
        queue.append((start_r, start_c, 0, 0))
        seen[0].add((start_r, start_c))
        while queue:
            row, col, keys, dist = queue.popleft()
            for new_r, new_c in (row + 1, col), (row - 1, col), (row, col + 1), (row, col - 1):
                if new_r < 0 or new_r >= m or new_c < 0 or new_c >= n or grid[new_r][new_c] == '#':
                    continue
                
                cell = grid[new_r][new_c]
                
                if cell in key_set and not ((1 << (ord(cell) - ord('a'))) & keys):
                    new_keys = (keys | (1 << (ord(cell) - ord('a'))))
                    
                    if new_keys == all_keys:
                        return dist + 1
                    seen[new_keys].add((new_r, new_c))
                    queue.append((new_r, new_c, new_keys, dist + 1))
                
                elif cell in lock_set and not (keys & (1 << (ord(cell) - ord('A')))):
                    continue
                
                elif (new_r, new_c) not in seen[keys]:
                    seen[keys].add((new_r, new_c))
                    queue.append((new_r, new_c, keys, dist + 1))
        
        return -1
            