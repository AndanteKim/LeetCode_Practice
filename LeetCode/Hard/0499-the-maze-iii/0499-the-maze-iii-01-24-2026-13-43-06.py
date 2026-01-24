class Solution:
    def findShortestWay(self, maze: List[List[int]], ball: List[int], hole: List[int]) -> str:
        def is_valid(x: int, y: int) -> bool:
            return 0 <= x < m and 0 <= y < n and maze[x][y] == 0

        def get_neighbors(row: int, col: int) -> List[Tuple[int]]:
            neighbors, directions = [], [(0, -1, 'l'), (-1, 0, 'u'), (0, 1, 'r'), (1, 0, 'd')]

            for dr, dc, d in directions:
                curr_r, curr_c = row, col
                dist = 0

                while is_valid(curr_r + dr, curr_c + dc):
                    curr_r += dr
                    curr_c += dc
                    dist += 1
                    if [curr_r, curr_c] == hole:
                        break
                
                neighbors.append((curr_r, curr_c, dist, d))
        
            return neighbors
        
        m, n, pq = len(maze), len(maze[0]), [(0, "", ball[0], ball[1])]
        seen, finished = set(), []

        while pq:
            curr_dist, path, r, c = heappop(pq)

            if (r, c) in seen:
                continue

            if [r, c] == hole:
                return path
            
            seen.add((r, c))

            for new_r, new_c, dist, d in get_neighbors(r, c):
                heappush(pq, (curr_dist + dist, path + d, new_r, new_c)) 

        return "impossible"