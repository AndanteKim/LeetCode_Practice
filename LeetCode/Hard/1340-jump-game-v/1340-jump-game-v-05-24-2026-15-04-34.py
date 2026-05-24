class Solution:
    def maxJumps(self, arr: List[int], d: int) -> int:
        def dfs(pos: int) -> None:
            if pos in seen:
                return
            
            seen[pos] = 1

            i = pos - 1
            while i >= 0 and pos - i <= d and arr[pos] > arr[i]:
                dfs(i)
                seen[pos] = max(seen[pos], seen[i] + 1)
                i -= 1
            i = pos + 1
            while i < n and i - pos <= d and arr[pos] > arr[i]:
                dfs(i)
                seen[pos] = max(seen[pos], seen[i] + 1)
                i += 1

        n, seen = len(arr), dict()
        for i in range(n):
            dfs(i)
        
        return max(seen.values())