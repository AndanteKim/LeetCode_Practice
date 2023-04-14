class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        queue, end, visited = deque([start]), len(arr) - 1, [False] * len(arr)
        
        while queue:
            index = queue.popleft()
            if arr[index] == 0:
                return True
            
            neg_jump, pos_jump = index - arr[index], index + arr[index]
            
            if 0 <= neg_jump <= end and not visited[neg_jump]:
                visited[neg_jump] = True
                queue.append(neg_jump)
            
            if 0 <= pos_jump <= end and not visited[pos_jump]:
                visited[pos_jump] = True
                queue.append(pos_jump)
        
        
        return False