class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        queue, cnt = deque([i for i in range(1, n + 1)]), 1
        
        while len(queue) > 1:
            curr = queue.popleft()
            
            if cnt == k:
                cnt = 1
            else:
                cnt += 1
                queue.append(curr)
        
        return queue[0]