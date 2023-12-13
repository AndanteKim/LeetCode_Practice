class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        r, c, ans = len(mat), len(mat[0]), 0
        queue = deque()
        
        for i in range(r):
            for j in range(c):
                if mat[i][j]:
                    queue.append((i, j))
                    
        while queue:
            row, col = queue.popleft()
            
            satisfied = True
            for i in range(r):
                if i != row and mat[i][col]:
                    satisfied = False
                    break
            
            if not satisfied:
                continue
            
            for i in range(c):
                if i != col and mat[row][i]:
                    satisfied = False
                    break
            
            if satisfied:
                ans += 1
        
        return ans
            
        