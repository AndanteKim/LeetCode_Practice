class Solution:
    def numberOfPatterns(self, m: int, n: int) -> int:
        jump = [[0] * 10 for _ in range(10)]
        
        # Initialize the jump over numbers for all valid jumps
        jump[1][3] = jump[3][1] = 2
        jump[4][6] = jump[6][4] = 5
        jump[7][9] = jump[9][7] = 8
        jump[1][7] = jump[7][1] = 4
        jump[2][8] = jump[8][2] = 5
        jump[3][9] = jump[9][3] = 6
        jump[1][9] = jump[9][1] = jump[3][7] = jump[7][3] = 5
        
        visited = [False] * 10
        ans, self.m, self.n = 0, m, n
        
        # Count patterns starting from corner numbers (1, 3, 7, 9) and multiply by 4 due to symmetry
        ans += self._count_patterns_from_number(1, 1, jump, visited) * 4
        
        # Count patterns starting from edge numbers (2, 4, 6, 8) and multiply by 4 due to symmetry
        ans += self._count_patterns_from_number(2, 1, jump, visited) * 4
        
        # Count patterns starting from the center number (5)
        ans += self._count_patterns_from_number(5, 1, jump, visited)
        
        return ans
        
    def _count_patterns_from_number(self, curr_num: int, curr_len: int, jump: List[List[int]], visited: List[bool]) -> int:
        # Base case: if current pattern length exceeds max length, stop exploring
        if curr_len > self.n:
            return 0
        
        valid_patterns = 0
        # If current pattern length is within the valid range, count it
        if curr_len >= self.m:
            valid_patterns += 1
        
        visited[curr_num] = True
        
        # Explore all possible next numbers
        for nxt_num in range(1, 10):
            jump_over_num = jump[curr_num][nxt_num]
            
            # Check if the next is unvisited and either:
            # 1. There's no number to jump over, or
            # 2. The number to jump over has been visited
            if not visited[nxt_num] and (jump_over_num == 0 or visited[jump_over_num]):
                valid_patterns += self._count_patterns_from_number(nxt_num, curr_len + 1, jump, visited)
                
        # Backtrack: unmark the current number before returning
        visited[curr_num] = False
        
        return valid_patterns
            

        
        
        