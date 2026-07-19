class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[int]:
        idx = sorted(range(n), key = lambda i: nums[i])
        pos = [0] * n

        for i, v in enumerate(idx):
            pos[v] = i
        
        m = n.bit_length()
        f = [[0] * m for _ in range(n)]

        left = 0
        for i in range(n):
            while left < i and nums[idx[i]] - nums[idx[left]] > maxDiff:
                left += 1
            f[i][0] = left
        
        for j in range(1, m):
            for i in range(n):
                f[i][j] = f[f[i][j - 1]][j - 1]
        
        ans = []

        for x, y in queries:
            u, v = pos[x], pos[y]
            if u > v:
                u, v = v, u
            
            if u == v:
                ans.append(0)
                continue
            
            step = 0
            for i in range(m - 1, -1, -1):
                if f[v][i] > u:
                    v = f[v][i]
                    step += 1 << i
            
            if f[v][0] <= u:
                ans.append(step + 1)
            else:
                ans.append(-1)
        
        return ans