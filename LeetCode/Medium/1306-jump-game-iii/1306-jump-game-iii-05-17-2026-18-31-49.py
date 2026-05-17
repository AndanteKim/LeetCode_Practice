class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        def dp(i: int, visited: Set[int] = set()) -> bool:
            if i < 0 or i >= n:
                return False

            if arr[i] == 0:
                return True
            
            if i in visited:
                return False
            visited.add(i)

            return dp(i - arr[i], visited) or dp(i + arr[i], visited)

        n = len(arr)
        return dp(start, set())