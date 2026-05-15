class Solution:
    def numberOfCleanRooms(self, room: List[List[int]]) -> int:
        def is_valid(row: int, col: int) -> bool:
            return 0 <= row < m and 0 <= col < n and room[row][col] != 1            
        
        
        DIRS = (0, 1, 0, -1, 0)
        m, n = len(room), len(room[0])
        ans = 0
        r, c, d = 0, 0, 0

        while not (room[r][c] >> (d + 1)) & 1:
            if room[r][c] == 0:
                ans += 1

            room[r][c] |= 1 << (d + 1)

            next_r, next_c = r + DIRS[d], c + DIRS[d + 1]

            if is_valid(next_r, next_c):
                r = next_r
                c = next_c
            else:
                d = (d + 1) % 4

        return ans        