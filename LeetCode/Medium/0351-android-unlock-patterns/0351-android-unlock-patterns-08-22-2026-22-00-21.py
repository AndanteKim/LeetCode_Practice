class Solution:
    def numberOfPatterns(self, m: int, n: int) -> int:
        self.single_mv = [
            (0, 1), (0, -1), (1, 0), (-1, 0),    # Adjacent moves
            (1, 1), (-1, 1), (1, -1), (-1, -1),  # Diagonal moves
            (-2, 1), (-2, -1), (2, 1), (2, -1),
            (1, -2), (-1, -2), (1, 2), (-1, 2)   # Extended moves
        ]

        self.skip_dot_mv = [
            (0, 2), (0, -2), (2, 0), (-2, 0),    # Straight skip
            (-2, -2), (2, 2), (2, -2), (-2, 2)   # Diagonal skip
        ]

        self.m, self.n = m, n
        ans = 0

        for r in range(3):
            for c in range(3):
                visited = [[False] * 3 for _ in range(3)]
                ans += self._cnt_patterns(1, r, c, visited)

        return ans

    def _cnt_patterns(self, curr_len: int, curr_r: int, curr_c: int, visited: List[List[bool]]) -> int:
        if curr_len > self.n:
            return 0
        
        valid = 0

        if curr_len >= self.m:
            valid += 1
        
        visited[curr_r][curr_c] = True

        for dr, dc in self.single_mv:
            new_r, new_c = curr_r + dr, curr_c + dc

            if self._is_valid(new_r, new_c, visited):
                valid += self._cnt_patterns(curr_len + 1, new_r, new_c, visited)
        
        for dr, dc in self.skip_dot_mv:
            new_r, new_c = curr_r + dr, curr_c + dc

            if self._is_valid(new_r, new_c, visited):
                mid_r, mid_c = curr_r + (dr >> 1), curr_c + (dc >> 1)

                if visited[mid_r][mid_c]:
                    valid += self._cnt_patterns(curr_len + 1, new_r, new_c, visited)
        
        visited[curr_r][curr_c] = False
        return valid

    def _is_valid(self, r: int, c: int, visited: List[List[bool]]) -> bool:
        return 0 <= r < 3 and 0 <= c < 3 and not visited[r][c]