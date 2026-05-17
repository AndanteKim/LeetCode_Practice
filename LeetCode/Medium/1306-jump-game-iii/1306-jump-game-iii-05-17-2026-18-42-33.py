class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        n, q = len(arr), deque([start])

        while q:
            node = q.popleft()

            if arr[node] == 0:
                return True

            if arr[node] < 0:
                continue

            for i in [node + arr[node], node - arr[node]]:
                if 0 <= i < n:
                    q.append(i)

            arr[node] = -arr[node]
        
        return False